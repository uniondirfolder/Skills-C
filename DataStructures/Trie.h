#pragma once
#include "TrieNode.h"
#include "Functions.h"

#ifndef TRIE_H
#define TRIE_H


template<typename T>
class Trie
{
public:
	Trie();
	~Trie();

	void insert(const T* value = nullptr);
	bool search(const T* value = nullptr);
	bool deleteValue(const T* value = nullptr);

private:
	TrieNode<T>* root = nullptr;
};

template<typename T>
inline Trie<T>::Trie()
{
	root = new TrieNode<T>();
}

template<typename T>
inline Trie<T>::~Trie()
{
	if (root != nullptr)
		delete root;
}

template<typename T>
inline void Trie<T>::insert(const T* value)
{
	TrieNode<T>* n = root;//"n" represents some prefix in "value"
	
	size_t length{ 0 };
	length = LengthOfArray(value);

	for (size_t i = 0; i < length; i++)
	{
		if (!n->haveRecord(value[i])) { n->addRecord(value[i], new TrieNode<T>(); }
		n = n->followChar(value[i]);
	}
	n->setIsWord(true);
}

template<typename T>
inline bool Trie<T>::search(const T* value)
{
	TrieNode<T>* n = root;

	size_t length{ 0 };
	length = LengthOfArray(value);

	for (size_t i = 0; i < length; i++)
	{
		if (!n->haveRecord(value[i])) { return false; }
		n = n->followChar(value[i]);
	}
	return n->getIsWord();
}

template<typename T>
inline bool Trie<T>::deleteValue(const T* value)
{
	TrieNode<T>* n = root;

	size_t length{ 0 };
	length = LengthOfArray(value);

	if (length) {// - must todo chek

		size_t pathLength = 0;
		TrieNode<T>** path = new TrieNode<T> * [length];
		for (size_t i = 0; i < length; i++)
		{
			if (!n->haveRecord(value[i])) 
			{
				//value is not in this tree
				return false;
			}
			n = n->followChar(value[i]);
			path[pathLength] = n;
			pathLength++;
		}
		n->setIsWord = false;

		//delete nodes that are no longer needed
		size_t inputIndex = length - 1; //from the end to 0
		//path[pathLength-1]==n
		if (pathLength >= 2) {
			for (size_t i = pathLength-2; i >= 0; i--)
			{
				if (n->haveNoRecord() &&
					(!n->getIsWord())
					) {
					//node can be deleted
					n = path[i];//i is index of parent node in path
					n->deleteRecord(value[inputIndex]);
					inputIndex--;
				}
				else 
				{
					//node cannot be deleted
					break;
				}
			}
			return true;
		}
		else
		{
			// ???

		}
	}

	return false;
}

#endif // !TRIE_H