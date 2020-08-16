#pragma once
#include "TrieNode.h"

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

}

template<typename T>
inline bool Trie<T>::search(const T* value)
{
	return false;
}

template<typename T>
inline bool Trie<T>::deleteValue(const T* value)
{
	return false;
}

#endif // !TRIE_H