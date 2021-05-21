#pragma once
#include "TNode.h"
#include "BTree.h"
using namespace std;
#include <vector>


namespace Tree {

	class BSTree : public BTree
	{

	public:
		BSTree():BTree(){};
		~BSTree();
		virtual TNode* find(char key);
		void Insert(Pair item);
		virtual void Delete(char key);
		void inOrderTravelToArr(TNode* arr) const ;

	private:

	};
	
}