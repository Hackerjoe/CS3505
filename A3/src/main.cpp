/*
*	Joseph Despain u0835107
*/

#include <iostream>
#include "Trie.h"
#include <vector>
#include <fstream>      // std::ifstream
using namespace std;

int main (int argc, char **argv)
{
	Trie* trie = new Trie;
	
	if(argv[1] != NULL)
	{
		string line;
		ifstream myfile (argv[1], std::ifstream::in);
		
		if (myfile.is_open())
		{
			while ( getline (myfile,line) )
			{
				trie->addWord(line);
			}
			myfile.close();
		}
		else
			cout << "File can not open. May not exist" << endl;
	}
	else
		cout << "First argument empty.";
	
	if(argv[2] != NULL)
	{
		string line;
		ifstream myfile (argv[2], std::ifstream::in);
		
		if (myfile.is_open())
		{
			while ( getline (myfile,line) )
			{
				if(trie->isWord(line))
				{
					cout << line << " is a word" << endl;
				}
				else
				{
					vector<string> listOfSimilar = trie->allWordsWithPrefix(line);
					cout << line << " is not found, did you mean: " << endl;
					if(listOfSimilar.size() != 0)
					{
						
						for(auto i = listOfSimilar.begin(); i != listOfSimilar.end(); ++i)
						{
						
							cout << "   " << *i << endl;
						}
					}
					else
						cout << "No alternate found" << endl;

				}
			}
			myfile.close();
		}
		else
			cout << "File can not open. May not exist" << endl;
	}

	
	vector<string> list;
	for(vector<string>::const_iterator i = list.begin(); i != list.end(); ++i)
	{
		cout << *i << " and ";
	}
	
	delete trie;
	
	return 0;
}
