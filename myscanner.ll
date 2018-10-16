%{
#include "ASTNode.h"
#include "microParser.hpp"
extern char* yytext;
%}

%%
"PROGRAM"		return PROGRAM;
"BEGIN"			return BEG;
"END"			return END;
"FUNCTION"		return FUNCTION;
"READ"			return READ;
"WRITE"			return WRITE;
"IF"			return IF;
"ELSE"			return ELSE;
"ENDIF"			return ENDIF;
"WHILE"			return WHILE;
"ENDWHILE"		return ENDWHILE;
"RETURN"		return RETURN;
"INT"			yylval.stringValue = strdup(yytext); return INT;
"VOID"			return VOID;
"STRING"		return STRING;
"FLOAT"			yylval.stringValue = strdup(yytext); return FLOAT;
"TRUE"			return TRUE;
"FALSE"			return FALSE;
--.*	                ;
":="			return DEF;
"+"			return ADD;
"-"			return SUB;
"*"			return MUL;
"/"			return DIV;
"="			return EQ;
"!="			return NEQ;
"<"			return LESS;
">"			return GRET;
"("			return LPAR;
")"			return RPAR;
;			return SEMI;
,			return COM;
"<="			return LEQ;
">="			return GEQ;

[a-zA-Z][_a-zA-Z0-9]*	yylval.stringValue = strdup(yytext); return IDENTIFIER;
[0-9][0-9]*		yylval.stringValue = strdup(yytext); return INTLITERAL;
[0-9]*\.[0-9][0-9]*	yylval.stringValue = strdup(yytext); return FLOATLITERAL;
\"(\\.|[^"\\])*\"	yylval.stringValue = strdup(yytext); return STRINGLITERAL;
[ \t\n]			;

%%

int yywrap(void)
{
	return 1;
}
