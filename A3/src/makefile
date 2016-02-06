CC = g++
CFLAGS = -Wall -std=c++11
SRCDIR = ./src


TrieTest : TrieTest.cpp Trie.o Node.o
	$(CC) $(CFLAGS) -o TrieTest TrieTest.cpp Trie.o Node.o

Node.o : Node.h Node.cpp
	$(CC) $(CFLAGS) -c -o Node.o Node.cpp

Trie.o : Trie.h Trie.cpp
	$(CC) $(CFLAGS) -c -o Trie.o Trie.cpp 

Test : TrieTest
	./TrieTest test.txt test2.txt

clean : 
	rm Trie.o Node.o TrieTest

