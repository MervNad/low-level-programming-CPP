/////////////////////////////////////////////////////////////////////////////////////////////
// File name         : tree.h
// Description       : represent a binary tree data structure.
// Programmer        : Merveilles Katumba Biende
// Date created      : 5-03-2024
// Date last revised : 12-03-2024
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TREE_H
#define TREE_H
#include "TreeNode.h"
#include <string>
using namespace std;

template <class BaseData>
class  tree
{      //friend class stated here;
public:
    tree();
    ~tree();
    tree(tree<BaseData>& t);
    tree<BaseData>& operator = (const tree<BaseData>& t);
    void insert(BaseData& item);
    void SearchAndDestroy(BaseData target);
    BaseData onlySearch(string empName);
    //'A' output all employees into the console by defalut
    void writeTree(int, char eCode = 'A', ostream& out = cout);
    int fullTree() const;
    int emptyTree() const;

protected:   //helping functions
    void remove(TreeNode<BaseData>*& current);
    void inOrder(TreeNode<BaseData>*, char eCode);
    void preOrder(TreeNode<BaseData>*, ostream& out);
    void postOrder(TreeNode<BaseData>*);
    void destroy(TreeNode<BaseData>* p);
    void copyTreeNode(TreeNode <BaseData>** into,
        TreeNode<BaseData>* from);
    void insertNode(TreeNode<BaseData>** into,
        BaseData& item);
    TreeNode <BaseData>* getnode(BaseData& item);

private:
    TreeNode<BaseData>* root;

};

#include "tree.t"
#endif