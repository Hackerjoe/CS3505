#include "Node.h"

Node::Node()
{

}

Node::Node(const Node& other)
{
	this->Value = other.Value;
	for (auto it = other.children.begin() ; it != other.children.end(); ++it)
	{
		cout << "hello from copy" << endl; 
		Node* NewNode = new Node(*(*it));
		cout << NewNode->GetValue() << endl;
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
	cout << "=" << endl;
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
	for(int i = 0; i < children.size(); i++)
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
