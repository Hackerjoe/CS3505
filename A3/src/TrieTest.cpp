/*
* Joseph Despain u0835107
* This program takes in one file which is the dictionary, and
* the second file is what words or simlar words you want to find.
*/

#include <iostream>
#include "Trie.h"
#include <vector>
#include <fstream>      // std::ifstream
using namespace std;

int main (int argc, char **argv)
{
	Trie* trie = new Trie;
	// Check for first argument.
	if(argv[1] != NULL)
	{
		string line;
		// Open File
		ifstream myfile (argv[1], std::ifstream::in);
		// Check if we can open file.
		if (myfile.is_open())
		{
			// Add words
			while ( getline (myfile,line) )
			{
				trie->addWord(line);
			}
			myfile.close();
		}
		else // File may not exist.
			cout << "File can not open in argument 1. May not exist" << endl;
	}
	else
		cout << "First argument empty.";
	
	// Check second argument.
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
					// Grab list of similar words
					vector<string> listOfSimilar = trie->allWordsWithPrefix(line);
					cout << line << " is not found, did you mean: " << endl;
					// Check if we have alternates for the word.
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
			cout << "File can not open in arugment 2. May not exist" << endl;
	}

	
	// Clean up, clean up, everybody do your share.
	delete trie;
	
	return 0;
}
