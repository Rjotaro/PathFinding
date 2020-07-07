translate: main.cpp
	g++ -c main.cpp

compile: main.o
	g++ -o main main.o

build:
	make translate
	make compile

clean:
	rm main.o main
