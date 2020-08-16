
#include <map>

using namespace std;

class TrieNode
{
	map<char, TrieNode*> table;
	bool isWord;

public:
	TrieNode() { isWord = false; }

	bool haveRecord(char &c) 
	{
		if (!table.empty())
		{
			auto search = table.find(c);
			if (search != table.end())
				return true;
			else
				return false;
		}
		else
			return false;
	}
};



