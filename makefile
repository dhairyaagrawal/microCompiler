# build and run team.c to print out team details

lex.yy.c : myscanner.ll
	@flex myscanner.ll

scanner : lex.yy.c myscanner.c
	@gcc myscanner.c lex.yy.c -o scanner.o

microParser.c : microParser.y
	@bison microParser.y -d -o microParser.c

compiler : microParser.c lex.yy.c myparser.c
	@gcc microParser.c lex.yy.c myparser.c -o myparser.o

clean : lex.yy.c microParser.c microParser.h
	@rm lex.yy.c microParser.c microParser.h

team.o : team.c
	@gcc -g -Wall team.c -o team.o

team : team.o
	@./team.o
