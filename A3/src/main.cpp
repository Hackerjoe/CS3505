#include <iostream>
#include "Trie.h"
#include <vector>
using namespace std;
int main()
{
	Trie* trie = new Trie;
	trie->addWord("cat");
	trie->addWord("cant");
	trie->addWord("catter");
	trie->addWord("free");
	trie->addWord("freedom");
	trie->addWord("hello");
	if(trie->isWord("hello"))
		std::cout << "is word" << std::endl;
	vector<string> list = trie->allWordsWithPrefix("ca");
	for(vector<string>::const_iterator i = list.begin(); i != list.end(); ++i) {
    // process i
    cout << *i << " and "; // this will print all the contents of *features*
	}
}
