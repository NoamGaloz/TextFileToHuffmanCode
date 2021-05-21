#include "Header.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This program gets text file as input and finds:																			//
//- An Huffman-code to every character from the file																		//
//- The weight of the text if was coded by Huffman (The sum of all characters weight-(len of code*frequency of character))	//
// Then the program prints the code and weight.																				//
//How Does The Huffman Code Is Obtaind:																						//
//1. building a binary search tree from the characters (the character is the key, the frequency of his show is the data).	//
//2. creating a minimum heap from the tree (the frequency is the key, the character is the data).							//
//3. building a huffman tree according to Huffman algoritem.																//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	ifstream infile;
	string fileName;
	BSTree t;
	TNode* treeInArr;
	BTree huffTree;
	vector<Weight> arr;
	cin >> fileName;
	infile.open(fileName);
	try {
		if (!infile)
			throw 0;
		buildBinarySearchTree(t, infile);
		if (t.getRoot() == nullptr)
			throw 0;
		else {
			int size = t.getVertNum();
			treeInArr = new TNode[size];
			convertTreeToArray(treeInArr, t);
			Heap Q(treeInArr, size);
			huffTree.setRoot(Huffman(Q, size));
			huffTree.printHuffCode(size,arr);
			printWeight(arr);
		}
	}
	catch (...)
	{
		cout << "invalid input"<< endl;
		exit(1);
	}

	infile.close();
}

void printWeight(vector<Weight> arr)
{
	int sum = 0;
	for (Weight i : arr)
	{
		sum += (i.pair.data * i.codeLen);
	}

	cout << "Encoded file weight: "<<sum <<" bits"<< endl;
}


TNode* Huffman(Heap leavesArr, int size)
{
	TNode* node;
	TNode* min1;
	TNode* min2;

	for (int i = 1; i < size; i++)
	{
		node = new TNode;
		min1 = leavesArr.DeleteMin();
		node->setLeft(min1);
		min2 = leavesArr.DeleteMin();
		node->setRight(min2);
		node->setFrequency(min1->getFrequency() + min2->getFrequency());
		leavesArr.insert(node);
	}

	return leavesArr.DeleteMin();
}

void buildBinarySearchTree(BSTree& t, ifstream& in)
{
	char input;
	in.get(input);
	while (!in.eof())
	{
		if (!in.good())
			throw 0;
		Pair newItem;
		newItem.key = input;
		t.Insert(newItem);
		in.get(input);
	}
}

void convertTreeToArray(TNode* arr, const BSTree& t)
{
	t.inOrderTravelToArr(arr);
	return;
}



