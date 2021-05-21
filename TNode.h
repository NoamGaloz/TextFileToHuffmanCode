#pragma once
using namespace std;
#include <stdlib.h>
#include <iostream>
#include <vector>
#define ENDL "\\n"
#define TAB "\\t"
#define SPACE " "


namespace Tree {

	typedef struct pair {
		char key; //the character
		int data = 1; //the frequency
	}Pair;


	typedef struct weight {
		Pair pair;
		int codeLen;
	}Weight;


	class TNode
	{
	public:
		TNode() { _left = _right = nullptr; };
		TNode(Pair item, TNode* left, TNode* right);
		~TNode();
		void operator=(const TNode& other);
		void InorderToArr(TNode* arr, int& idx);
		int getFrequency() const;
		void setFrequency(int num);
		void setLeft(TNode* node);
		void setRight(TNode* node);
		TNode* deleteNode(TNode* t, char key);
		TNode* deleteNodeBS(TNode* t, char key);
		TNode* find(char key);
		TNode* findMaxBS(TNode* root);
		void printHuffCode(int* code, int idx, vector<Weight>& arr);
		bool isLeaf();
		void printKey();
		

		friend class BSTree;

	private:
		Pair _val;
		TNode* _left, * _right;

	};
}


