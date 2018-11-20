%{
	#include "ASTNode.h"
    #include <iostream>
    #include <sstream>
    #include <stdio.h>
	#include <cstdlib>
	#include <string.h>
	#include <string>
	#include <list>
    #include "stack.h"
    #include "table.h"
    #include "table_entry.h"
%}


%{
    extern int yylex();
    extern int yylineno;
    extern char * yytext;
    void yyerror(const char * s) {
        //printf("Error Line %d token %s\n",yylineno,yytext);
    }

    stack* myStack = NULL;
    std::list<ASTNode*>* listAST = NULL;
    std::string varType = "FLOAT";
    int scope = 1;
    int flag = 0;
		int decl = 1;
		int io_flag = 0;
    table currTable;
    table globalTable;
    ASTNode *tmpNode = NULL;
    ASTNode *listID = NULL;
    std::ostringstream os;
%}

%union{
	int intValue;
    float floatValue;
    char * stringValue;
    ASTNode *treeNode;

}

%token  END "end of file"
%token  IDENTIFIER INTLITERAL FLOATLITERAL STRINGLITERAL
%token  PROGRAM BEG FUNCTION READ WRITE IF ELSE ENDIF WHILE ENDWHILE RETURN INT VOID STRING FLOAT TRUE FALSE
%token  DEF ":=" ADD "+" SUB "-" MUL "*" DIV "/" EQ "=" NEQ "!=" LESS "<" GRET ">" LPAR "(" RPAR ")" SEMI ";" COM "," LEQ "<=" GEQ ">="

%type <stringValue> id str var_type;
%type <treeNode> addop mulop expr expr_prefix factor factor_prefix primary postfix_expr assign_expr assign_stmt cond compop call_expr expr_list expr_list_tail;

%%
program:  {myStack = new stack; globalTable = currTable = table("Symbol table GLOBAL"); listAST = new std::list<ASTNode*>;} PROGRAM id BEG pgm_body END {myStack->push(currTable);};
id:       IDENTIFIER {if(io_flag) {$$ = $<stringValue>1;} else {if(!decl) {std::string s = currTable.index($<stringValue>1); if(s == "") {$$ = $<stringValue>1;} else {$$ = (strdup(s.c_str()));}} else {$$ = $<stringValue>1;}}} ;
pgm_body: decl func_declarations;
decl:     string_decl decl | var_decl decl | ;

string_decl:  STRING id ":=" str ";" {currTable.add(table_entry("STRING", ($<stringValue>2), ($<stringValue>4)));};
str:          STRINGLITERAL {$$ = $<stringValue>1;};

var_decl:   var_type {flag = 1;} id_list ";"
var_type:   FLOAT {varType = "FLOAT";} | INT {varType = "INT";};
any_type:   var_type | VOID;
id_list:    id {if(flag) {currTable.add(table_entry(varType, ($<stringValue>1), ""));}
				else {varType = currTable.search($<stringValue>1);
				if(varType == "") {varType = "STRING";}
				std::string s = currTable.index($<stringValue>1); if(s == "") {s = $<stringValue>1;}
				tmpNode->right = new ASTNode(s,varType); tmpNode = tmpNode->right;}}
			id_tail;
id_tail:    "," id {if(flag) {currTable.add(table_entry(varType, ($<stringValue>2), ""));}
					else {varType = currTable.search($<stringValue>2);
					if(varType == "") {varType = "STRING";}
					std::string s = currTable.index($<stringValue>2); if(s == "") {s = $<stringValue>2;}
					tmpNode->right = new ASTNode(s,varType); tmpNode = tmpNode->right;}}
			id_tail | ;

param_decl_list:    param_decl param_decl_tail | ;
param_decl:         var_type id {currTable.add(table_entry(($<stringValue>1), ($<stringValue>2), ""));};
param_decl_tail:    "," param_decl param_decl_tail | ;

func_declarations:  func_decl func_declarations | ;
func_decl:          FUNCTION {decl = 1;} any_type id {listAST->push_back(new ASTNode($<stringValue>4, "FUNC")); myStack->push(currTable); currTable = table("Symbol table " + std::string($<stringValue>4));} "(" param_decl_list ")" {currTable.pos = currTable.entries.size();} BEG func_body END {listAST->push_back(new ASTNode("END", "END"));} ;
func_body:          decl {decl = 0; std::stringstream os; os << (currTable.entries.size() - currTable.pos); listAST->push_back(new ASTNode(os.str(), "LINK"));} stmt_list;

stmt_list:          stmt stmt_list | ;
stmt:               base_stmt | if_stmt | loop_stmt;
base_stmt:          assign_stmt | read_stmt | write_stmt | control_stmt;

assign_stmt:        assign_expr {listAST->push_back($<treeNode>1);} ";";
assign_expr:        id ":=" expr
					{
					varType = currTable.search_Stack($<stringValue>1);
					tmpNode = new ASTNode($<stringValue>1,varType);
					if($<treeNode>3->type == "PP"){
					$$ = new ASTNode(tmpNode, $<treeNode>3, "POP", varType, NULL);
					} else {
					$$ = new ASTNode(tmpNode, $<treeNode>3, ":=", varType, NULL);}
					} ;
read_stmt:          {flag = 0; listID = new ASTNode("READ","READ"); tmpNode = listID;} READ "(" {io_flag = 1;} id_list {io_flag = 0;} ")" ";" {listAST->push_back(listID);};
write_stmt:         {flag = 0; listID = new ASTNode("WRITE","WRITE"); tmpNode = listID;} WRITE "(" {io_flag = 1;} id_list {io_flag = 0;} ")" ";" {listAST->push_back(listID);};
return_stmt:        RETURN expr ";" {std::stringstream ss; ss << currTable.pos + 6; tmpNode = new ASTNode(ss.str(), "RETURN"); tmpNode->right = $<treeNode>2; listAST->push_back(tmpNode);} ;

expr:               expr_prefix factor
					{if($<treeNode>1 == NULL)
					{$$ = $<treeNode>2;}
					else
					{$<treeNode>1->right = $<treeNode>2; $$ = $<treeNode>1;}};
expr_prefix:        expr_prefix factor addop
					{if($<treeNode>1 == NULL)
					{$<treeNode>3->left = $<treeNode>2;}
					else
					{$<treeNode>1->right = $<treeNode>2; $<treeNode>3->left = $<treeNode>1;}
					$$ = $<treeNode>3;}
					| {$$ = NULL;};
factor:             factor_prefix postfix_expr
					{if($1 == NULL)
					{$$ = $<treeNode>2;}
					else
					{$<treeNode>1->right = $<treeNode>2; $$ = $<treeNode>1;}};
factor_prefix:      factor_prefix postfix_expr mulop
					{if($1 == NULL)
					{$<treeNode>3->left = $<treeNode>2;}
					else
					{$<treeNode>1->right = $<treeNode>2; $<treeNode>3->left = $<treeNode>1;}
					$$ = $<treeNode>3;}
					| {$$ = NULL;};
postfix_expr:       primary {$$ = $<treeNode>1;} | call_expr {$$ = $<treeNode>1;} ;
call_expr:          id "(" expr_list ")" {listAST->push_back(new ASTNode("PUSHREGS", "PUSHREGS")); $$ = new ASTNode($<stringValue>1, "PP");};
expr_list:          expr {tmpNode = new ASTNode("ARG", "ARG"); tmpNode->right = $<treeNode>1; listAST->push_back(tmpNode);} expr_list_tail | {$$ = NULL;} ;
expr_list_tail:     "," expr {tmpNode = new ASTNode("ARG", "ARG"); tmpNode->right = $<treeNode>2; listAST->push_back(tmpNode);} expr_list_tail  | {$$ = NULL;} ;
primary:            "(" expr ")" {$$ = $<treeNode>2;} | id {varType = currTable.search_Stack($<stringValue>1); $$ = new ASTNode($<stringValue>1,varType);} | INTLITERAL {$$ = new ASTNode($<stringValue>1,"INT");} | FLOATLITERAL {$$ = new ASTNode($<stringValue>1,"FLOAT");};
addop:              "+" {$$ = new ASTNode("+");} | "-" {$$ = new ASTNode("-");};
mulop:              "*" {$$ = new ASTNode("*");} | "/" {$$ = new ASTNode("/");};

if_stmt:             IF "(" cond ")" {$<treeNode>3->type = "IF"; listAST->push_back($<treeNode>3);} decl stmt_list else_part ENDIF {listAST->push_back(new ASTNode("end", "ENDIF"));} ;
else_part:           ELSE {listAST->push_back(new ASTNode("else", "ELSE"));} decl stmt_list | ;
cond:                expr compop expr {$<treeNode>2->right = $<treeNode>3; $<treeNode>2->left = $<treeNode>1; $$ = $<treeNode>2;}
					| TRUE {$$ = NULL;}
					| FALSE {$$ = NULL;};
compop:              "<" {$$ = new ASTNode("<");}
					| ">" {$$ = new ASTNode(">");}
					| "=" {$$ = new ASTNode("=");}
					| "!=" {$$ = new ASTNode("!=");}
					| "<=" {$$ = new ASTNode("<=");}
					| ">=" {$$ = new ASTNode(">=");};
while_stmt:          WHILE "(" cond ")" {$<treeNode>3->type = "WHILE"; listAST->push_back($<treeNode>3);} decl stmt_list ENDWHILE {listAST->push_back(new ASTNode("end", "ENDWHILE"));} ;

control_stmt:        return_stmt;
loop_stmt:           while_stmt;
