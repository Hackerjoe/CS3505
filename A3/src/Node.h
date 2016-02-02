/* Joseph Despain u0835107
*
*/
#include <string>
#include <vector>

class Node 
{
public:
	bool isEndOfWord();
	void addChild(char value)
	void SetMarkEnd();
	void SetValue(char value);
	Node* GetChild(char value);
private:
	char Value;
	bool word;
	vector<Node*> children;
};
