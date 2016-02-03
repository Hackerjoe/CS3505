#include <iostream>
#include "Trie.h"
#include <vector>
using namespace std;
int main()
{
	Trie* trie = new Trie;
	trie->addWord("hello");
	trie->addWord("hel");
	trie->addWord("he");
	
	if(trie->isWord("hello"))
		std::cout << "is word" << std::endl;
	vector<string> list = trie->allWordsWithPrefix("h");
	for(vector<string>::const_iterator i = list.begin(); i != list.end(); ++i) {
    // process i
    cout << *i << " "; // this will print all the contents of *features*
	}
}
