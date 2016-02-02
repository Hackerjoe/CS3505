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
	Node* CurrentNode = root;
	
	// Check if the string is empty if so return.
	if(word.length() == 0)
		return;
	
	// Loop through the word
	for(int i = 0; i < word.length(); i++)
	{
		// Grab the child node associated with the character from the current node.
		Node* Child = CurrentNode->GetChild(word[i]);
		
		// If not null the child node is the current node.
		if(Child != NULL)
		{
			CurrentNode = Child;
		}
		else // If the child node is empty we add a new child node to the current.
		{
			Node* NewNode = new Node();
			// Set the new nodes value.
			NewNode->SetValue(word[i]);
			CurrentNode->addChildNode(NewNode);
			CurrentNode = NewNode;
		}
		
		// If we are at the end of the word set the word mark to true.
		if(word.length() - 1 == i)
			CurrentNode->SetMarkEnd();	
	}
}

bool Trie::isWord(string word)
{
	
	if(word.length() == 0)
		return false;

	Node* CurrentNode = root;
	
	for(int i = 0; i < word.length(); i++)
	{
		Node* NextNode = CurrentNode->GetChild(word[i]);
		if(NextNode != NULL)
			CurrentNode = NextNode;
		else
			return NULL;		
	}
	
	if(CurrentNode->isEndOfWord() == true)
		return true;
	else
		return false;
	
	return false;
}

vector<string> Trie::allWordsWithPrefix(string word)
{
	vector<string> returnResult;
	return returnResult;
}
