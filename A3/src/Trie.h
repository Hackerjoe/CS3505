/* Joseph Despain u0835107
*
*/

#include <string>
#include <vector>
#include "Node.h"
#include <iostream>
#include <algorithm>
using namespace std;
class Trie
{

public:

	Trie();
	~Trie();

	Trie(const Trie& other);
    Trie& operator=(Trie& other);

	void addWord(string word);
	bool isWord(string word);
	vector<string> allWordsWithPrefix(string word);

	void TestCopyRoot();
private:
	vector<string> SearchNode(Node* node, string word);
	Node* root;
};
