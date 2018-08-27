# build and run team.c to print out team details

team.o : team.c
	@gcc -g -Wall team.c -o team.o

team : team.o
	@./team.o
