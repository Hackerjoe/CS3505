#include <iostream>
#include "Trie.h"

int main()
{
	Trie* trie = new Trie;
	trie->addWord("hello");
	if(trie->isWord("helo"))
		std::cout << "is word" << std::endl;
}
