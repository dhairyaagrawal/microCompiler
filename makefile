# build and run team.c to print out team details

lex.yy.c : myscanner.ll
	@flex myscanner.ll

scanner : lex.yy.c myscanner.c
	@gcc myscanner.c lex.yy.c -o scanner.o

microParser.cpp : microParser.y
	@bison microParser.y -d -o microParser.cpp

compiler : microParser.cpp lex.yy.c
	@g++ microParser.cpp lex.yy.c myparser.cpp table.cpp stack.cpp table_entry.cpp ASTNode.cpp CodeObject.cpp IRNode.cpp -o myparser.o

clean : lex.yy.c microParser.cpp microParser.hpp
	@rm lex.yy.c microParser.cpp microParser.hpp

team.o : team.c
	@gcc -Wall team.c -o team.o

team : team.o
	@./team.o
