/*
*	Joseph Despain u0835107
*/

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
	
	trie->TestCopyRoot();

	if(trie->isWord("cat"))
		std::cout << "is word" << std::endl;
	
	vector<string> list = trie->allWordsWithPrefix("ca");
	for(vector<string>::const_iterator i = list.begin(); i != list.end(); ++i)
	{
		cout << *i << " and ";
	}
	
	delete trie;
	
	return 0;
}
