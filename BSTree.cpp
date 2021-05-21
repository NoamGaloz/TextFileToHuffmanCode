#include "BSTree.h"


namespace Tree {

    BSTree::~BSTree()
    {
        if (_root != nullptr)
        {
            delete _root;
            _root = nullptr;
        }
    }
 
    //finds and returns a node by the given key.
    TNode* BSTree::find(char key)
    {
        TNode* temp;
        temp = _root;
        while (temp != nullptr)
        {
            if (key == (temp->_val).key)
                return temp;
            else if (key < (temp->_val).key)
                temp = temp->_left;
            else
                temp = temp->_right;
        }
        return nullptr;
    }

    //creats a node with the given pair and inserts it in the right place in tree
    void BSTree::Insert(Pair item)
    {
        TNode* temp = find(item.key);

        if (temp != nullptr) //if the key already exist in the tree, increase by 1 the frequency (data) of the existing node.
        {
            temp->_val.data += item.data;
            return;
        }

        TNode* curr = _root;
        TNode* parent = nullptr;
        TNode* newNode;

        while (curr != nullptr) //find the parent of the node to insert him as child.
        {
            parent = curr;
            if (item.key < (curr->_val.key))
                curr = curr->_left;
            else curr = curr->_right;
        }

        newNode = new TNode(item, nullptr, nullptr);
        if (parent == nullptr) _root = newNode; //tree was empty- insert node as root.
        else if (item.key < parent->_val.key) parent->_left = newNode;
        else parent->_right = newNode;

        verticesNum += 1;

    }

    //deletes a node using a function from class TNode.
    void BSTree::Delete(char key)
    {
        _root = _root->deleteNodeBS(_root, key);
    }

    //gets an arr and traveling inorder on the tree to copy his data to the arr.
    void BSTree::inOrderTravelToArr(TNode* arr) const
    {
        int idx = 0;
        if (_root == nullptr) return;
       if(_root->_left!=nullptr) _root->_left->InorderToArr(arr,idx);
        arr[idx]._val=_root->_val;
        idx++;
        if (_root->_right != nullptr) _root->_right->InorderToArr(arr,idx);
    }
}