#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "BSTree.h"
#include "Heap.h"
#include <algorithm>

using namespace Tree;
using namespace H;
using namespace std;

//calcultes and prints the weight of the file
void printWeight(vector<Weight> arr);
//creates an huffman tree from the heap and returns his root.
TNode* Huffman(Heap leavesArr, int size);
//creates a binary search tree from the file characters (character=key,number of shows in file =data).
void buildBinarySearchTree(BSTree& t, ifstream& in);
//creates an array and copies the binary search tree data by traveling inorder on the tree.
void convertTreeToArray(TNode* arr, const BSTree& t);