#pragma once
#include "TNode.h"

namespace Tree {
	class BTree
	{
	public:
		BTree() :_root(nullptr) {};
		~BTree();
		TNode* getRoot() const;
		void setRoot(TNode* root);
		int getVertNum() const;
		bool isEmpty() const;
		void makeEmpty();
		virtual TNode* find(char key);
		virtual void Delete(char key);
		void printHuffCode(int size, vector<Weight>& arr);
		void printRoot();

	protected:
		TNode* _root;
		int verticesNum = 0;
	};

}