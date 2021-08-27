all:derle bagla run

derle:
	g++ -I ./include -c ./src/Stack.cpp -o ./lib/Stack.o
	g++ -I ./include -c ./src/Kisi.cpp -o ./lib/Kisi.o
	g++ -I ./include -c ./src/AVL.cpp -o ./lib/AVL.o
	g++ -I ./include -c ./src/Node.cpp -o ./lib/Node.o
	g++ -I ./include -c ./src/Test.cpp -o ./lib/Test.o
bagla:
	g++ ./lib/AVL.o ./lib/Node.o ./lib/Kisi.o ./lib/Stack.o ./lib/Test.o -o ./bin/Test.exe
run:
	./bin/Test