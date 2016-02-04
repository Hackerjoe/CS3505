/* Joseph Despain u0835107
*
*/
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
private:
	char Value;
	bool word;
	vector<Node*> children;
};
