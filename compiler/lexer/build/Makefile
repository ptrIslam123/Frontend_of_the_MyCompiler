compil:
	clang++ -c ../*.cpp

compilToken:
	clang++ -c ../token.cpp

compilGrammae:
	clang++ -c ../lexer_tokens_grammar.cpp


compilLexer:
	clang++ -c ../lexer.cpp



compilTest:
	clang++ -c ../test/*.cpp


link: *.o
	clang++ *.o -o main


run:
	./main


buildTest:
	make compilTest
	make link


build:
	make compil
	make link


clear: *.o
	rm *.o
	clear
