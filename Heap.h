#pragma once
#include "TNode.h"
#include <algorithm>
using namespace Tree;
using namespace std;

namespace H {
	class Heap
	{
	public:
		Heap(int size);
		Heap(TNode* arr,int size); // BuildHeap according to floyd algorytem.
		~Heap() { if (isAllocated) delete[] data; data = nullptr;};
		void insert(TNode* item);
		void fixHeap(int node);
		const TNode& Min();
		TNode* DeleteMin();
		
		int getLeft(int node) const;
		int getRight(int node) const;
		int getParent(int node) const;

	private:
		TNode* data;
		int physSize;
		int logSize;
		bool isAllocated;
	};

	void swap(TNode* node1, TNode* node2);

}