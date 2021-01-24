compilFile:
	clang++ -c ../file/*.cpp

compilMain:
	clang++ -c ../*.cpp

compil:
	make compilFile
	make compilMain	

link:
	clang++ *.o -o main

run:
	./main

buildMain:
	make compilMain
	make link

build:
	make compil
	make link


clear:
	rm *.o
	clear