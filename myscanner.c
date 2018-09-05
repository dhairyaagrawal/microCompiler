#include <stdio.h>
#include "myscanner.h"

extern int yylex();
extern char* yytext;

int main(void)
{
	int token;
	char* type;
	char* definitions[] = {"IDENTIFIER", "INTLITERAL", "FLOATLITERAL", "STRINGLITERAL", "COMMENT"};
	token = yylex();
	while(token)
	{	
		if(token > 0 && token < 19)
		{
			type = "KEYWORD";
		}
		else if(token > 18 && token < 34)
		{
			type = "OPERATOR";
		}
		else if(token > 33 && token < 39)
		{
			type = definitions[token - 34];
		}
		else
		{
			printf("Error\n");
		}
		printf("Token Type: %s\n", type);
		printf("Value: %s\n", yytext);
		token = yylex();
	}
	return 0;
}
