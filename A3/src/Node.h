/* Joseph Despain u0835107
* Node class is created for the Trie class, but 
* can be used just as a basic node class.
* The node class nows its children and its parent.
*/

#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node 
{
public:
	Node();
	~Node();
	Node(const Node& other);
    Node& operator=(Node& other);

	bool isEndOfWord();
	void addChildNode(Node* node);
	void SetMarkEnd();
	void SetValue(char value);
	Node* GetChild(char value);
	char GetValue();
	int GetLength();
	vector<char> GetChildrenValues();
	Node* GetParent();
	void SetParent(Node* node);
private:
	char Value;
	bool word;
	Node* Parent;
	vector<Node*> children;
};
#endif
