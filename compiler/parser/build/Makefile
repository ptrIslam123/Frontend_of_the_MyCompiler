compilLexer:
	clang++ -c ../../lexer/*.cpp


compil:
	clang++ -c ../*.cpp
	make compilLexer

compilMain:
	clang++ -c ../main.cpp




link:	
	clang++ *.o -o main


buildMain:
	make compilMain
	make link


build:
	make compil
	make link


run:
	./main


clear:	
	rm *.o
	clear