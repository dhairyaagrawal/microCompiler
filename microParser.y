%{
    #include <stdio.h>
    #include <string.h>
    extern int yylex();
    extern int yylineno;
    extern char * yytext;
    void yyerror(const char * s) {
        //printf("Error Line %d token %s\n",yylineno,yytext);
    }
    char* varType = "FLOAT";
    int scope = 1;
    int flag = 0;
%}

%union{
    int intValue;
    float floatValue;
    char *stringValue;
}

%token  END "end of file"
%token  IDENTIFIER INTLITERAL FLOATLITERAL STRINGLITERAL
%token  PROGRAM BEG FUNCTION READ WRITE IF ELSE ENDIF WHILE ENDWHILE RETURN INT VOID STRING FLOAT TRUE FALSE
%token  DEF ":=" ADD "+" SUB "-" MUL "*" DIV "/" EQ "=" NEQ "!=" LESS "<" GRET ">" LPAR "(" RPAR ")" SEMI ";" COM "," LEQ "<=" GEQ ">="
%%

%type <stringValue> id str var_type id_list;

program:  {printf("Symbol table GLOBAL\n");} PROGRAM id BEG pgm_body END;
id:       IDENTIFIER {$$ = $<stringValue>1;};
pgm_body: decl func_declarations;
decl:     string_decl decl | var_decl decl | ;

string_decl:  STRING id ":=" str ";" {printf("name %s type STRING value %s\n", $2, $4);};
str:          STRINGLITERAL {$$ = $<stringValue>1;};

var_decl:   var_type {flag = 1;} id_list ";"
var_type:   FLOAT {$$ = $<stringValue>1; varType = "FLOAT";} | INT {$$ = $<stringValue>1; varType = "INT";};
any_type:   var_type | VOID;
id_list:    id {if(flag) {printf("name %s type %s\n", $<stringValue>1, varType);}} id_tail;
id_tail:    "," id {if(flag) {printf("name %s type %s\n", $<stringValue>2, varType);}} id_tail | ;

param_decl_list:    param_decl param_decl_tail | ;
param_decl:         var_type id {printf("name %s type %s\n", $<stringValue>2, $<stringValue>1);};
param_decl_tail:    "," param_decl param_decl_tail | ;

func_declarations:  func_decl func_declarations | ;
func_decl:          FUNCTION any_type id {printf("\nSymbol table %s\n", $<stringValue>3);} "(" param_decl_list ")" BEG func_body END;
func_body:          decl stmt_list;

stmt_list:          stmt stmt_list | ;
stmt:               base_stmt | if_stmt | loop_stmt;
base_stmt:          assign_stmt | read_stmt | write_stmt | control_stmt;

assign_stmt:        assign_expr ";";
assign_expr:        id ":=" expr;
read_stmt:          {flag = 0;} READ "(" id_list ")" ";";
write_stmt:         {flag = 0;} WRITE "(" id_list ")" ";";
return_stmt:        RETURN expr ";";

expr:               expr_prefix factor;
expr_prefix:        expr_prefix factor addop | ;
factor:             factor_prefix postfix_expr;
factor_prefix:      factor_prefix postfix_expr mulop | ;
postfix_expr:       primary | call_expr;
call_expr:          id "(" expr_list ")";
expr_list:          expr expr_list_tail | ;
expr_list_tail:     "," expr expr_list_tail | ;
primary:            "(" expr ")" | id | INTLITERAL | FLOATLITERAL;
addop:              "+" | "-";
mulop:              "*" | "/";

if_stmt:             {printf("\nSymbol table BLOCK %d\n", scope); scope++;} IF "(" cond ")" decl stmt_list else_part ENDIF;
else_part:           {printf("\nSymbol table BLOCK %d\n", scope); scope++;} ELSE decl stmt_list | ;
cond:                expr compop expr | TRUE | FALSE;
compop:              "<" | ">" | "=" | "!=" | "<=" | ">=";
while_stmt:          {printf("\nSymbol table BLOCK %d\n", scope); scope++;} WHILE "(" cond ")" decl stmt_list ENDWHILE;

control_stmt:        return_stmt;
loop_stmt:           while_stmt;
