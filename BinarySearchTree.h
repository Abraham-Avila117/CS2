#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <cassert>
#include "binaryTree.h"
//#include <bits/stdc++.h> // yes its included. no it was never used

using namespace std;
template<class elemType>
class bSearchTreeType: public binaryTreeType<elemType>
{
public:
bool search(const elemType& searchItem) const;
//Function to determine if searchItem is in the binary
//search tree.
//Postcondition: Returns true if searchItem is found in the
// binary search tree; otherwise, returns false.
void insert(const elemType& insertItem);
//Function to insert insertItem in the binary search tree.
//Postcondition: If there is no node in the binary search
// tree that has the same info as insertItem,
// a node with the info insertItem is created
// and inserted in the binary search tree.
void deleteNode(const elemType& deleteItem);
//Function to delete deleteItem from the binary search tree
//Postcondition: If a node with the same info as deleteItem
// is found, it is deleted from the binary
// search tree.
// If the binary tree is empty or deleteItem
// is not in the binary tree, an appropriate
// message is ptinted.

private:
void deleteFromTree(binaryTreeNode<elemType>* &current, binaryTreeNode<elemType>* &prev);
//Function to delete the node to which p points is deleted
//from the binary search tree.
//Postcondition: The node to which p points is deleted
// from the binary search tree.

//find the rightmost left of node
binaryTreeNode<elemType>* findCandidateRight(binaryTreeNode<elemType>* curr, binaryTreeNode<elemType>* &prev);
//find the leftmost right of node
binaryTreeNode<elemType>* findCandidateLeft(binaryTreeNode<elemType>* curr, binaryTreeNode<elemType>* &prev);
//search for nullptr to insert to tree
binaryTreeNode<elemType>* searchToInsert(binaryTreeNode<elemType>*&, const elemType&);
//make a new node to be inserted
binaryTreeNode<elemType>* getNewNode(const elemType&);
};

template<class elemType>
bool bSearchTreeType<elemType>::search(const elemType& searchItem) const //works
{
    binaryTreeNode<elemType>* searchPtr = this->root;
    while(searchPtr != nullptr)
    {
        if(searchPtr->info == searchItem)
            return true; //item found
        else if(searchPtr->info > searchItem)
            searchPtr = searchPtr->llink;
        else if(searchPtr->info < searchItem)
            searchPtr = searchPtr->rlink;
    }
    return false; //item not found
}

template<class elemType>
binaryTreeNode<elemType>* bSearchTreeType<elemType>::getNewNode(const elemType& item)
{
    binaryTreeNode<elemType>* newNode = new binaryTreeNode<elemType>;
    newNode->info = item;
    newNode->llink = newNode->rlink = nullptr;
    return newNode;
}

template<class elemType>
binaryTreeNode<elemType>* bSearchTreeType<elemType>::searchToInsert(binaryTreeNode<elemType>* &insertPtr, const elemType& item)
{
    if(insertPtr == nullptr)
    {
        insertPtr = getNewNode(item);
        assert(insertPtr!=nullptr);
    }
    else if(item == insertPtr->info)
        return nullptr;
    else if(item < insertPtr->info)
        insertPtr->llink = searchToInsert(insertPtr->llink, item);
    else
        insertPtr->rlink = searchToInsert(insertPtr->rlink, item);
    return insertPtr;
}

template<class elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem)//works
{
    searchToInsert(this->root, insertItem);
}

template<class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType& deleteItem) //works
{
    binaryTreeNode<elemType>* deletePtr = this->root, *prevPtr = nullptr;
    if(this->isEmpty())
    {
        cerr << "Tree is Empty. Nothing to delete" << endl;
        return;
    }

    while(deletePtr != nullptr) //search through the tree for deleteItem
    {
        if(deletePtr->info == deleteItem)
            break;
        else if(deletePtr->info > deleteItem)
        {
            prevPtr = deletePtr;
            deletePtr = deletePtr->llink;
        }
        else if(deletePtr->info < deleteItem)
        {
            prevPtr = deletePtr;
            deletePtr = deletePtr->rlink;
        }
        if(deletePtr == nullptr)
        {
            cerr << "item not found" << endl;
            return;
        }
    }
    deleteFromTree(deletePtr, prevPtr);
}

template<class elemType>
void bSearchTreeType<elemType>::deleteFromTree(binaryTreeNode<elemType>* &current, binaryTreeNode<elemType>* &prev)//changed and works
{
    if(current->llink == nullptr && current->rlink == nullptr)//leaf
    {
        delete current;
        current = nullptr;
    }
    else if(current->llink == nullptr && prev->rlink == current)//current with only right link & previous right is current
    {
        prev->rlink = current->rlink;
        delete current;
        current = nullptr;
    }
    else if(current->llink == nullptr && prev->llink == current)//current with only right link & previous left is current
    {
        prev->llink = current->llink;
        delete current;
        current = nullptr;
    }
    else if(current->rlink == nullptr && prev->llink == current)//current with only left link & previous right is current
    {
        prev->llink = current->llink;
        delete current;
        current = nullptr;
    }
    else if(current->rlink == nullptr && prev->rlink == current)//current with only left link & previous left is current
    {
        prev->rlink = current->llink;
        delete current;
        current = nullptr;
    }
    else //current had two children
    {
        prev = current;
        binaryTreeNode<elemType>* can = findCandidateRight(current->rlink, prev);
        current->info = can->info;
        if(prev->llink == can)
            prev->llink = can->rlink;
        else
            prev->rlink = can->rlink;
        delete can;
        can = nullptr;
    }
}

template<class elemType>
binaryTreeNode<elemType>* bSearchTreeType<elemType>::findCandidateRight(binaryTreeNode<elemType>* curr, binaryTreeNode<elemType>* &prev)
{
    if(curr->llink == nullptr)
        return curr;
    else
    {
        prev = curr;
        return findCandidateRight(curr->llink, prev);
    }
}

template<class elemType>
binaryTreeNode<elemType>* bSearchTreeType<elemType>::findCandidateLeft(binaryTreeNode<elemType>* curr, binaryTreeNode<elemType>* &prev)
{
    if(curr->rlink == nullptr)
        return curr;
    else
    {
        prev = curr;
        return findCandidateLeft(curr->rlink, prev);
    }
}

#endif // BINARYSEARCHTREE_H
