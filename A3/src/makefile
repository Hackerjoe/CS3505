CC = g++
CFLAGS = -Wall -std=c++11
SRCDIR = ./src

Node.o : Node.h Node.cpp
	$(CC) $(CFLAGS) -c -o Node.o Node.cpp

Trie.o : Trie.h Trie.cpp
	$(CC) $(CFLAGS) -c -o Trie.o Trie.cpp 

Main : main.cpp Trie.o Node.o
	$(CC) $(CFLAGS) -o main main.cpp Trie.o Node.o

Test : Main
	./Main

clean : 
	rm Trie.o Node.o main

