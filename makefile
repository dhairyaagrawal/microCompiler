# build and run team.c to print out team details

lex.yy.c : myscanner.ll
	@flex myscanner.ll

compiler : lex.yy.c myscanner.c
	@gcc -Wall myscanner.c lex.yy.c -o myscanner.o

clean : lex.yy.c myscanner.o
	@rm lex.yy.c myscanner.o

team.o : team.c
	@gcc -g -Wall team.c -o team.o

team : team.o
	@./team.o
