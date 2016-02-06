/*
* Joseph Despain u0835107
*/

#include "Trie.h"

Trie::Trie()
{
	root = new Node();
}

Trie::~Trie()
{
	delete root;
}

Trie::Trie(const Trie& other)
{
	Node* NewRoot = new Node(*(other.root));
	this->root = NewRoot;
}

Trie& Trie::operator=(Trie& other)
{
	swap(root,other.root);
	return *this;
}


void Trie::addWord(string word)
{
	Node* CurrentNode = root;
	
	// Check if the string is empty if so return.
	if(word.length() == 0)
		return;
	
	// Loop through the word
	for(unsigned int i = 0; i < word.length(); i++)
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
			NewNode->SetParent(CurrentNode);
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
	// entered nothing forget it.
	if(word.length() == 0)
		return false;

	Node* CurrentNode = root;
	// Go down the tree to find the word/
	for(unsigned int i = 0; i < word.length(); i++)
	{
		// Grab child node.
		Node* NextNode = CurrentNode->GetChild(word[i]);
		// If the next node is null the word does not exist.
		if(NextNode != NULL)
			CurrentNode = NextNode;
		else
			return false;		
	}
	
	// Now we are at the end check if it is a word in the dictionary.
	if(CurrentNode->isEndOfWord() == true)
		return true;
	else
		return false;
	
	return false;
}

vector<string> Trie::allWordsWithPrefix(string word)
{
	vector<string> returnResult;
	
	Node* CurrentNode = root;
	
	// Blank string was entered return all words.
	if(word.length() == 0)
		return this->SearchNode(CurrentNode,"");

	// Move down the trie with the prefix.
	for(unsigned int i = 0; i < word.length(); i++)
	{
		if(CurrentNode != NULL)
			CurrentNode = CurrentNode->GetChild(word[i]);
		else
			break;
	}
	// If the node is not null search the node and the children.
	if(CurrentNode != NULL)
		returnResult = this->SearchNode(CurrentNode, word);
	
	return returnResult;
}

/*
* This function recursively checks the nodes and their children
* for words.
*
*/
vector<string> Trie::SearchNode(Node* node, string word)
{
	vector<string> returnResult;

	if(node == NULL)
		return returnResult;

	// Get Children Values
	vector<char> ChildrenValues = node->GetChildrenValues();
	// iterate through children.
	for (auto it = ChildrenValues.begin() ; it != ChildrenValues.end(); ++it)
	{
		// Get Child
		Node* Child = node->GetChild((*it));
		// If it is end of word add to the return result.
		if(Child->isEndOfWord() == true)
		{
			// Get word returns the full word.
			returnResult.push_back(GetWord(Child,""));
		}
		
		// Now recursively check the child for words.
		vector<string> RecResult = this->SearchNode(Child,word);
		for (auto it = RecResult.begin() ; it != RecResult.end(); ++it)
		{
			returnResult.push_back((*it));
		}
	}
	
	return returnResult;
}

/*
* Get word goes back up the trie to get the word.
*/
string Trie::GetWord(Node* node,string word)
{
	if(node == NULL)
		return "";
	string returnResult = "";
	returnResult = node->GetValue();
	returnResult = GetWord(node->GetParent(), returnResult) + returnResult;
	return returnResult;
}
