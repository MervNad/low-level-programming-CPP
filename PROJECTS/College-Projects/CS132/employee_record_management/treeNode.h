/////////////////////////////////////////////////////////////////////////////////////////////
// File name         : treeNode.h
// Description       : Represent a node in the binary tree.
// Programmer        : Merveilles Katumba Biende
// Date created      : 5-03-2024
// Date last revised : 12-03-2024
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TREENode_H
#define TREENode_H

template <class BaseData>
struct  TreeNode
{
    BaseData TreeData;
    TreeNode* left, * right;
};

#endif