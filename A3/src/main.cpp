/*
*	Joseph Despain u0835107
*/

#include <iostream>
#include "Trie.h"
#include <vector>
using namespace std;

int main()
{
	/*Trie* trie = new Trie;

	trie->addWord("cat");
	trie->addWord("cant");
	trie->addWord("catter");
	trie->addWord("free");
	trie->addWord("freedom");
	trie->addWord("hello");
	trie->TestCopyRoot();
	if(trie->isWord("hello"))
		std::cout << "is word" << std::endl;

	vector<string> list = trie->allWordsWithPrefix("ca");
	for(vector<string>::const_iterator i = list.begin(); i != list.end(); ++i)
	{
		//cout << *i << " and ";
	}
	
	delete trie;*/
	
	Node* hello = new Node();
	hello->SetValue('a');
	Node test = *hello;
	delete hello;
	cout << test.GetValue() << endl;
	
	return 0;
}
