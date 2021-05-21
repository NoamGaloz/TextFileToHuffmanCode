#include "BTree.h"


namespace Tree {

	BTree::~BTree()
	{
		if (_root != nullptr)
		{
			delete _root;
			_root = nullptr;
		}
	}

	TNode* BTree::getRoot() const
	{
		return _root;
	}

	void BTree::setRoot(TNode* root)
	{
		_root = root;
	}

	int BTree::getVertNum() const
	{
		return verticesNum;
	}

	bool BTree::isEmpty() const
	{
		return (_root==nullptr);
	}

	TNode* BTree::find(char key)
	{
		return _root->find(key);
	}


	void BTree::Delete(char key)
	{
		_root = _root->deleteNode(_root, key);
	}

	//prints the Huffman code using a function from class TNode
	void BTree::printHuffCode(int size, vector<Weight>& arr)
	{
		if (_root == nullptr) return;
		cout << "Character encoding:" << endl;
		int idx = 0;
		int* code=new int[size];
		_root->printHuffCode(code, idx, arr);
		
		delete[] code;
	}

	void BTree::printRoot()
	{
		cout << _root->getFrequency() << endl;
	}


	void BTree::makeEmpty()
	{
		delete[] _root;
	}

}