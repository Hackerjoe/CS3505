/*
* Joseph Despain u0835107
* Trie class creates a trie for a dictionary. 
* Trie can see if words are in the dictionary.
* Trie can check for words with prefixes.
*/

#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include "Node.h"
#include <iostream>
#include <algorithm>
using namespace std;
class Trie
{

public:

	Trie();
	~Trie();

	Trie(const Trie& other);
    Trie& operator=(Trie& other);

	void addWord(string word);
	bool isWord(string word);
	vector<string> allWordsWithPrefix(string word);
	string GetWord(Node* node,string word);
	void TestCopyRoot();
private:
	vector<string> SearchNode(Node* node, string word);
	Node* root;
};
#endif
