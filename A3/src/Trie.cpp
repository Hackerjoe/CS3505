#include "Trie.h"

Trie::Trie()
{
	root = new Node();
}

Trie::~Trie()
{
	delete root;
}

void Trie::addWord(string word)
{

}

bool Trie::isWord(string word)
{
	return false;
}

vector<string> Trie::allWordsWithPrefix(string word)
{
	vector<string> returnResult;
	return returnResult;
}
