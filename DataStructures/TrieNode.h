#pragma once
#include "amain.h"
#ifndef TRIENODE_H
#define TRIENODE_H



template<typename T>
class TrieNode
{
public:
	TrieNode<T>() = default;

	bool haveRecord(T c);
	bool haveNoRecord();
	TrieNode<T>* followChar(T c);
	void addRecord(T c, TrieNode<T>* n);
	void deleteRecord(T c);
	bool getIsWord();
	void setIsWord(bool isWord);

private:
	map<T, TrieNode<T>*> table;
	bool isWord{ false };
};


template<typename T>
inline bool TrieNode<T>::haveRecord(T c)
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

template<typename T>
inline bool TrieNode<T>::haveNoRecord()
{
	return table.empty();
}

template<typename T>
inline TrieNode<T>* TrieNode<T>::followChar(T c)
{
	TrieNode<T>* node = NULL;

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

template<typename T>
inline void TrieNode<T>::addRecord(T c, TrieNode<T>* n)
{
	if (haveRecord(c))
	{
		auto find = table.find(c);
		if (find != table.end())
			table.erase(find);
	}
}

template<typename T>
inline void TrieNode<T>::deleteRecord(T c)
{
}

template<typename T>
inline bool TrieNode<T>::getIsWord()
{
	return isWord;
}

template<typename T>
inline void TrieNode<T>::setIsWord(bool isWord)
{
	this.isWord = isWord;
}

#endif // !TRIENODE_H