
#include <map>

using namespace std;

class TrieNode1
{
	
public:
	TrieNode1() { isWord = false; }

	bool haveRecord(char c) 
	{
		if (!haveNoRecord())
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

	bool haveNoRecord() 
	{ return table.empty(); }

	TrieNode1* followChar(char c) 
	{
		TrieNode* node = nullptr;

		if (!haveNoRecord())
		{
			auto search = table.find(c);
			if (search != table.end())
			{
				node = search->second;
			}
		}

		return node;
	}

	void addRecord(char c, TrieNode1* n) 
	{
		if (!haveRecord(c)) 
		{
			table.insert(make_pair(c, n));
		}
	}

	void deleteRecord(char c) 
	{
		if (haveRecord(c)) 
		{
			auto find = table.find(c);
			if (find != table.end())
				table.erase(find);
		}
	}

	bool getIsWord()
	{ 
		return isWord;
	}

	void setIsWord() 
	{
		isWord = true;
	}

private:
	map<char, TrieNode1*> table;
	bool isWord;
};



