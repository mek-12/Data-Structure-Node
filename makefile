hepsi:derle calistir

derle:
	g++ -I ./include/ -o ./lib/Hata.o -c ./src/Hata.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Top.o ./src/Test.cpp

calistir:
	./bin/Test