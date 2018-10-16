%{
	#include "ASTNode.h"
    #include <iostream>
    #include <stdio.h>
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
    
    stack* myStack = nullptr;
    std::list<ASTNode*>* listAST = nullptr;
    std::string varType = "FLOAT";
    int scope = 1;
    int flag = 0;
    table *currTable = nullptr;
    ASTNode *tmpNode = nullptr;
    ASTNode *listID = nullptr;
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
%type <treeNode> addop mulop expr expr_prefix factor factor_prefix primary postfix_expr assign_expr assign_stmt;

%%
program:  {myStack = new stack; currTable = new table("Symbol table GLOBAL"); listAST = new std::list<ASTNode*>;} PROGRAM id BEG pgm_body END {myStack->push(currTable);}; 
id:       IDENTIFIER {$$ = $<stringValue>1;};
pgm_body: decl func_declarations;
decl:     string_decl decl | var_decl decl | ;

string_decl:  STRING id ":=" str ";" {currTable->add(new table_entry("STRING", ($<stringValue>2), ($<stringValue>4)));};
str:          STRINGLITERAL {$$ = $<stringValue>1;};

var_decl:   var_type {flag = 1;} id_list ";"
var_type:   FLOAT {varType = "FLOAT";} | INT {varType = "INT";};
any_type:   var_type | VOID;
id_list:    id {if(flag) {currTable->add(new table_entry(varType, ($<stringValue>1), ""));}
				else {varType = myStack->tables[0]->search($<stringValue>1); tmpNode->right = new ASTNode($<stringValue>1,varType); tmpNode = tmpNode->right;}} 
			id_tail;
id_tail:    "," id {if(flag) {currTable->add(new table_entry(varType, ($<stringValue>2), ""));}
					else {varType = myStack->tables[0]->search($<stringValue>2); tmpNode->right = new ASTNode($<stringValue>2,varType); tmpNode = tmpNode->right;}} 
			id_tail | ;

param_decl_list:    param_decl param_decl_tail | ;
param_decl:         var_type id {currTable->add(new table_entry(($<stringValue>1), ($<stringValue>2), ""));};
param_decl_tail:    "," param_decl param_decl_tail | ;

func_declarations:  func_decl func_declarations | ;
func_decl:          FUNCTION any_type id {myStack->push(currTable); currTable = new table("Symbol table " + std::string($<stringValue>3));} "(" param_decl_list ")" BEG func_body END;
func_body:          decl stmt_list;

stmt_list:          stmt stmt_list | ;
stmt:               base_stmt | if_stmt | loop_stmt;
base_stmt:          assign_stmt | read_stmt | write_stmt | control_stmt;

assign_stmt:        assign_expr {listAST->push_back($<treeNode>1);} ";";
assign_expr:        id ":=" expr {varType = myStack->tables[0]->search($<stringValue>1); tmpNode = new ASTNode($<stringValue>1,varType); $$ = new ASTNode(tmpNode, $<treeNode>3, ":=", varType, nullptr);};
read_stmt:          {flag = 0; listID = new ASTNode("READ","READ"); tmpNode = listID;} READ "(" id_list ")" ";" {listAST->push_back(listID);};
write_stmt:         {flag = 0; listID = new ASTNode("WRITE","WRITE"); tmpNode = listID;} WRITE "(" id_list ")" ";" {listAST->push_back(listID);};
return_stmt:        RETURN expr ";";

expr:               expr_prefix factor 
					{if($<treeNode>1 == nullptr) 
					{$$ = $<treeNode>2;} 
					else 
					{$<treeNode>1->right = $<treeNode>2; $$ = $<treeNode>1;}};
expr_prefix:        expr_prefix factor addop 
					{if($<treeNode>1 == nullptr) 
					{$<treeNode>3->left = $<treeNode>2;} 
					else 
					{$<treeNode>1->right = $<treeNode>2; $<treeNode>3->left = $<treeNode>1;} 
					$$ = $<treeNode>3;} 
					| {$$ = nullptr;};
factor:             factor_prefix postfix_expr 	
					{if($1 == nullptr) 
					{$$ = $<treeNode>2;} 
					else 
					{$<treeNode>1->right = $<treeNode>2; $$ = $<treeNode>1;}};
factor_prefix:      factor_prefix postfix_expr mulop 
					{if($1 == nullptr) 
					{$<treeNode>3->left = $<treeNode>2;} 
					else 
					{$<treeNode>1->right = $<treeNode>2; $<treeNode>3->left = $<treeNode>1;} 
					$$ = $<treeNode>3;} 
					| {$$ = nullptr;};
postfix_expr:       primary {$$ = $<treeNode>1;} | call_expr {$$ = nullptr;};
call_expr:          id "(" expr_list ")";
expr_list:          expr expr_list_tail | ;
expr_list_tail:     "," expr expr_list_tail | ;
primary:            "(" expr ")" {$$ = $<treeNode>2;} | id {varType = myStack->tables[0]->search($<stringValue>1); $$ = new ASTNode($<stringValue>1,varType);} | INTLITERAL {$$ = new ASTNode($<stringValue>1,"INT");} | FLOATLITERAL {$$ = new ASTNode($<stringValue>1,"FLOAT");};
addop:              "+" {$$ = new ASTNode("+");} | "-" {$$ = new ASTNode("-");};
mulop:              "*" {$$ = new ASTNode("*");} | "/" {$$ = new ASTNode("/");};

if_stmt:             {myStack->push(currTable); currTable = new table("Symbol table BLOCK " + std::to_string(scope)); scope++;} IF "(" cond ")" decl stmt_list else_part ENDIF;
else_part:           {myStack->push(currTable); currTable = new table("Symbol table BLOCK " + std::to_string(scope)); scope++;} ELSE decl stmt_list | ;
cond:                expr compop expr | TRUE | FALSE;
compop:              "<" | ">" | "=" | "!=" | "<=" | ">=";
while_stmt:          {myStack->push(currTable); currTable = new table("Symbol table BLOCK " + std::to_string(scope)); scope++;} WHILE "(" cond ")" decl stmt_list ENDWHILE;

control_stmt:        return_stmt;
loop_stmt:           while_stmt;
