#include "Node.h"

Node::Node()
{

}

Node::Node(const Node& other)
{
	this->Value = other.Value;
	this->word = other.word;
	for (auto it = other.children.begin() ; it != other.children.end(); ++it)
	{
		Node* NewNode = new Node(*(*it));
		this->addChildNode(NewNode);
	}
}

Node::~Node()
{
	for (auto it = children.begin() ; it != children.end(); ++it)
    {
		delete (*it);
    }
	children.clear(); 
}

Node& Node::operator=(Node& other)
{
	swap(Value,other.Value);
	swap(word, other.word);
	swap(children, other.children);
	return *this;
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

vector<char> Node::GetChildrenValues()
{
	vector<char> returnResult;
	for (auto it = children.begin() ; it != children.end(); ++it)
	{
		returnResult.push_back((*it)->GetValue());
	}
	return returnResult;
}
