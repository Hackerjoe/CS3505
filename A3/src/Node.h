/* Joseph Despain u0835107
*
*/
#include <string>
#include <vector>

using namespace std;

class Node 
{
public:
	Node();
	~Node();
	bool isEndOfWord();
	void addChildNode(Node* node);
	void SetMarkEnd();
	void SetValue(char value);
	Node* GetChild(char value);
	char GetValue();
	int GetLength();
private:
	char Value;
	bool word;
	vector<Node*> children;
};
