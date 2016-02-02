/* Joseph Despain u0835107
*
*/

#include <string>
#include <vector>
#include "Node.h"
using namespace std;
class Trie
{

public:

	Trie();
	~Trie();
	void addWord(string word);
	bool isWord(string word);
	vector<string> allWordsWithPrefix(string word);

private:
	
	Node* root;
};
