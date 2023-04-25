#ifndef BINARYTREETYPE_H
#define BINARYTREETYPE_H


#include <iostream>
using namespace std;
//define a node
template<class elemType>
struct binaryTreeNode
{
    elemType info;
    binaryTreeNode<elemType>* llink, *rlink;
};

// class definition
template<class elemType>
class binaryTreeType
{
    public:
        //assignment op
        binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&);

        //isempty
        bool isEmpty() const;

        //traversals all 3
        void inorderTraversal() const;
        void postorderTraversal() const;
        void preorderTraversal() const;

        //treeheight
        int treeHight() const;

        //tree node count
        int treeNodeCount() const;

        //tree leaves count
        int treeLeavesCount() const;

        //destroy tree
        void destroyTree();

        binaryTreeType(const binaryTreeType& otherTree);
        binaryTreeType();
        ~binaryTreeType();

    protected:
        binaryTreeNode<elemType>* root;

    private:
        void copyTree(binaryTreeType<elemType>*& copiedTreeRoot, binaryTreeType<elemType>* otherTreeRoot);
        void destroy(binaryTreeNode<elemType>*& p);
        void inorder(binaryTreeNode<elemType>* p) const;
        void preorder(binaryTreeNode<elemType>* p) const;
        void postorder(binaryTreeNode<elemType>* p) const;
        int height(binaryTreeNode<elemType>* p) const;
        int max(int x, int y) const;
        int nodeCount(binaryTreeNode<elemType>* p) const;
        int leavesCount(binaryTreeNode<elemType>* p) const;

};

template<class elemType>
binaryTreeType<elemType>::binarTreeType()
{
    root = nullptr;
}

template<class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return(root==nullptr);
}

template<class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
    postorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
    preorder(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

template<class elemType>
void binaryTreeType<elemType>::copyTree(binaryTreeNode<elemType>*& copiedTreeRoot, binaryTreeNode<elemType>* otherTreeRoot)
{
    if(otherTreeRoot == nullptr)
        copiedTreeRoot == nullptr;
    else
    {
        copiedTreeRoot = new binaryTreeNode<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
}

template<class elemType>
void binaryTreeType<elemType>::inorder(binaryTreeNode<elemType>* p) const
{
    if(p != nullptr)
    {
        inorder(p->llink);
        cout << p->info <<" ";
        inorder(p->rlink);
    }
}

template<class elemType>
void binaryTreeType<elemType>::preorder(binaryTreeNode<elemType>* p) const
{
    if(p != nullptr)
    {
        cout << p->info <<" ";
        preorder(p->llink);
        preorder(p->rlink);
    }
}

template<class elemType>
void binaryTreeType<elemType>::postorder(binaryTreeNode<elemType>* p) const
{
    if(p != nullptr)
    {
        postorder(p->llink);
        postorder(p->rlink);
        cout << p->info <<" ";
    }
}


template<class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::operator=(const binaryTreeType<elemType>& otherTree) const
{
    if(this != &otherTree)
    {
        if(root != nullptr)//if has stuff destroy it
            destroy(root);
        if(otherTree.root == nullptr)
            root = nullptr;
        else
            copyTree(root, otherTree.root);
    }
}

template<class elemType>
void binaryTreeType<elemType>::destroy(binaryTreeNode<elemtype>*& p)
{
    if(p != nullptr)
    {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p=nullptr;
    }
}

template<class elemType>
void binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

template<class elemType>
void binaryTreeType<elemType>::height(binaryTreeNode<elemType> *p) const
{
    if(p==nullptr)
        return 0;
    else
        return 1 + max(height(p->llink), height(p->rlink));
}

template<class elemType>
void binaryTreeType<elemType>::max(int x, int y)
{
    if(x >= y)
        return x;
    else
        return y;
}

template<class elemType>
int binaryTreeType<elemType>::nodeCount(binarTreeNode<elemType> *p) const
{
    if(p == nullptr)
        return 0;
    else
        return 1 + (nodeCount(p->llink) + nodeCount(p->rlink));
}

template<class elemType>
int binaryTreeType<elemType>::leavesCount(binaryTreeNode<elemType> *p) const
{
    if(p == nullptr)
        return 0;
    else if(p->llink == nullptr && p->rlink == nullptr)
        return 1;
    else
        return leavesCount(p->llink) + leavesCount(p->rlink);
}

binaryTreeType::~binaryTreeType()
{
    root = nullptr;
}

#endif // BINARYTREETYPE_H
