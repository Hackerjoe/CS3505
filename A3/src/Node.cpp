/*
* Joseph Despain u0835107
*
*/

#include "Node.h"

Node::Node()
{

}

Node::Node(const Node& other)
{
	this->Value = other.Value;
	this->word = other.word;
	// Create and add children nodes.
	for (auto it = other.children.begin() ; it != other.children.end(); ++it)
	{
		// Recursively create child nodes.
		Node* NewNode = new Node(*(*it));
		NewNode->Parent = this;
		this->addChildNode(NewNode);
	}
}

Node::~Node()
{
	// Delete all children
	for (auto it = children.begin() ; it != children.end(); ++it)
    {
		delete (*it);
    }
	// Clear vector
	children.clear(); 
}

Node& Node::operator=(Node& other)
{
	swap(Value,other.Value);
	swap(word, other.word);
	swap(children, other.children);
	swap(Parent, other.Parent);
	return *this;
}

void Node::SetParent(Node* node)
{
	this->Parent = node;
}

bool Node::isEndOfWord()
{
	return word;
}

void Node::addChildNode(Node* node)
{
	if(this->GetChild(node->GetValue()) == NULL)
		children.push_back(node);
}

void Node::SetValue(char value)
{
	Value = value;
}

void Node::SetMarkEnd()
{
	word = true;
}

char Node::GetValue()
{
	return Value;
}

Node* Node::GetChild(char value)
{
	for(unsigned int i = 0; i < children.size(); i++)
	{
		Node* CurrentChild = children.at(i);
		if(CurrentChild->GetValue() == value)
		{
			return CurrentChild;
		}
	}
	
	return NULL;
}

int Node::GetLength()
{
	return children.size();
}

Node* Node::GetParent()
{
	return Parent;
}
vector<char> Node::GetChildrenValues()
{
	vector<char> returnResult;
	for (auto it = children.begin() ; it != children.end(); ++it)
	{
		returnResult.push_back((*it)->GetValue());
	}
	return returnResult;
}
