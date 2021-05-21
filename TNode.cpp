#include "TNode.h"

namespace Tree {

	TNode::TNode(Pair item, TNode* left, TNode* right)
	{
		_val = item;
		_left = left;
		_right = right;
	}

	TNode::~TNode()
	{
		if (_left != nullptr)
			delete _left;
		if (_right != nullptr)
			delete _right;
	}

	void TNode::operator=(const TNode& other)
	{
		 _left = other._left;
		_right = other._right;
		_val = other._val;
	}

	//traveling recursively inorder on the tree and copy the data to the arr
	void TNode::InorderToArr(TNode* arr, int& idx)
	{
		if (_left != nullptr) _left->InorderToArr(arr,idx);
		arr[idx]._val=_val;
		idx++;
		if (_right != nullptr) _right->InorderToArr(arr,idx);
	}


	int TNode::getFrequency() const
	{
		return _val.data;
	}

	void TNode::setFrequency(int num)
	{
		_val.data = num;
	}

	//insert left chile to a node
	void TNode::setLeft(TNode* node)
	{
		_left = node;
	}

	//insert right chile to a node
	void TNode::setRight(TNode* node)
	{
		_right = node;
	}

	//recursive function who deletes a node (according to his key)
	TNode* TNode::deleteNode(TNode* t, char key)
	{
		if (t == nullptr) return t;
		else if (key < t->_val.key)
			t->_left = deleteNodeBS(t->_left, key);
		else if (key > _val.key)
			t->_right = _right->deleteNodeBS(t->_right, key);
		else //are equals
		{
			if (t->isLeaf())
			{
				delete t;
				return nullptr;
			}
			else if (t->_left == nullptr)//has only right child
			{
				TNode* temp = t->_right;
				delete t;
				return temp;
			}
			else //has only left child
			{
				TNode* temp = t->_left;
				delete t;
				return temp;
			}
		}

	}

	//delete node function in binary search tree by .
	TNode* TNode::deleteNodeBS(TNode* t,char key)
	{
		if (t == nullptr) return t;
		if (key < t->_val.key)
			t->_left=deleteNodeBS(t->_left,key);
		else if (key > _val.key)
			t->_right=_right->deleteNodeBS(t->_right,key);
		else {
			if (t->_left == nullptr)
			{
				TNode* temp = t->_left;
				delete t;
				return temp;
			}
			else if (t->_right == nullptr)
			{
				TNode* temp = t->_right;
				delete t;
				return temp;
			}

			TNode* tempMax = findMaxBS(t->_left);
			t->_val = tempMax->_val;
			t->_left = deleteNodeBS(t->_left, key);
		}
		return t;
	}

	//finds and returns a node according to a given key
	TNode* TNode::find(char key)
	{
		if (_val.key == key) return this;
		if (_left != nullptr)
			_left->find(key);
		if (right != nullptr)
			_right->find(key);
		return nullptr;
	}

	//finds and returns the max node in binary search tree
	TNode* TNode::findMaxBS(TNode* root)
	{
		TNode* curr = root;
		while ((curr != nullptr) && (curr->_right != nullptr))
		{
			curr = curr->_right;
		}
		return curr;
	}

	//recursively travelling on the tree and prints the Huffman code that obtained.
	void TNode::printHuffCode(int* code ,int idx, vector<Weight>& arr)
	{
		if (isLeaf())
		{
			Weight w;
			if (idx == 0)//only one character to code
			{
				w.codeLen = 1;
				code[idx] = 1;
				idx = 1;
			}
			else
				w.codeLen = idx;
			w.pair = _val;
			arr.push_back(w);
			printKey();
			for (int i = 0; i < idx; i++)
				cout << code[i];
			cout << endl;
			return;
		}
		if (_left != nullptr)
		{
			code[idx] = 0;
			_left->printHuffCode(code,idx+1,arr);
		}
		if (_right != nullptr)
		{
			code[idx] = 1;
			_right->printHuffCode(code,idx+1,arr);
		}
	}

	bool  TNode::isLeaf()
	{
		return ((_left == nullptr) && (_right == nullptr));
	}

	//prints the characters with spaciel treatment to \t \n and enter.
	void TNode::printKey()
	{
		cout << "'";
		if (_val.key == 32)
		{
			cout << SPACE;
		}
		else if (_val.key == 9)
		{
			cout << TAB;
		}
		else if (_val.key == 10)
		{
			cout << ENDL;
		}
		else
			cout << _val.key; 

		cout << "'" << " - ";
	}
}

