//
// Created by mby on 30/06/2020.
//
#include <iostream>
#include <cassert>
#include "BST.h"

using std::cout;
using std::cin;
using std::endl;

//------------------Auxiliary functions----------------------
inline int ReadValue()
{
   int value;
   cin >> value;

   return value;
}

inline bool StillHasInput()
{
    return !cin.eof();
}

void InitNode(TreeNode* node, int val)
{
    assert(node);

    node->m_data = val;
    node->m_left = NULL;
    node->m_right = NULL;
}

TreeNode* CreateNode(int value)
{
    TreeNode* node = new TreeNode;
    InitNode(node, value);

    return node;
}

void InsertNode(TreeNode** root, TreeNode* newNode)
{
    assert(root && newNode);

    if (!*root)
    {
        //Special case: Tree is empty
        *root = newNode;
    }
    else
    {
        //Otherwise, trivial case
        if (newNode->m_data < (*root)->m_data)
        {
            InsertNode(&(*root)->m_left, newNode);
        }
        else if(newNode->m_data > (*root)->m_data)
        {
            InsertNode(&(*root)->m_right, newNode);
        }
        else
        {
            delete newNode;
        }
    }
}
TreeNode* min(TreeNode* node){
    while(node->m_left){
        node=node->m_left;
    }
    return node;
}
bool checkLeaf(TreeNode* node){
    return (node->m_left==NULL) && (node->m_right==NULL);
}
bool checkOneSon(TreeNode* node){
    return (node->m_left==NULL) || (node->m_right==NULL);
}
void removeLeaf(TreeNode** node){
    free(*node);
    node=NULL;
}
void removeNodeWithOneSon(TreeNode** node){
    *node = ((*node)->m_right==NULL )? (*node)->m_left : (*node)->m_right;
}
void removeNodeWithTwoSon(TreeNode** node){
    TreeNode* help=(min((*node)->m_right));
    TreeNode** successor=&help;
    (*node)->m_data = (*successor)->m_data;
    if(checkLeaf(*successor)){
        removeLeaf(successor);
    } else
        removeNodeWithOneSon(successor);
}
void find_leaf(TreeNode*** root, int val){
    while((**root)->m_data!=val){
        if(val>(**root)->m_data)
            *root = &(**root)->m_right;
        else
            *root = &(**root)->m_left;
    }
}
//--------------------------------------------------------------

void InsertNode(TreeNode** root, int val)
{
    InsertNode(root, CreateNode(val));
}

TreeNode* BuildBST()
{
    TreeNode *root = NULL;
    TreeNode *newNode = NULL;

    int value = ReadValue();

    while (StillHasInput())
    {
        newNode = CreateNode(value);
        InsertNode(&root, newNode);
        value = ReadValue();
    }

    cin.clear();
    return root;
}

void DestroyBST(TreeNode** root)
{
    if (*root)
    {
        DestroyBST(&(*root)->m_left);
        DestroyBST(&(*root)->m_right);
        delete *root;
    }
    *root = NULL;
}

void PrintBST(TreeNode* root, PrintFunc func)
{
    func(root);
    cout<<endl;
}

void PrintInOrder(TreeNode* root)
{
    if(root)
    {
        PrintInOrder(root->m_left);
        cout << root->m_data << " ";
        PrintInOrder(root->m_right);
    }
}

void PrintPreOrder(TreeNode* root)
{
    if(root)
    {
        cout << root->m_data << " ";
        PrintPreOrder(root->m_left);
        PrintPreOrder(root->m_right);
    }
}

void PrintPostOrder(TreeNode* root)
{
    if(root)
    {
        cout << root->m_data << " ";
        PrintPostOrder(root->m_right);
        PrintPostOrder(root->m_left);
    }
}

void removeNode(TreeNode **root ,int val){
    assert(root);
    TreeNode** tmp = root;
    find_leaf(&tmp,val);
    if(checkLeaf(*tmp)){
        removeLeaf(tmp);
    }
    else{
        if(checkOneSon(*tmp)){
            removeNodeWithOneSon(tmp);
        }
        else{
            removeNodeWithTwoSon(tmp);
        }
    }
}

int getDepth(TreeNode* root){
    if(!root)
        return 0;
    int right = getDepth(root);
    int left = getDepth(root);
    return (right>left ? right:left)+1;
}

bool isExists(TreeNode* root , int val){
    if(root==NULL){
        return  false;
    }
    if(root->m_data==val){
        return true;
    }
    return isExists(root->m_right,val)|| isExists(root->m_left,val);
}

bool  isEqual(TreeNode* root1,TreeNode* root2){
    if(!root1 || !root2)
        return root1==root2;
    return root1->m_data==root2->m_data && isEqual(root1->m_left,root2->m_left) && isEqual(root1->m_right,root2->m_right);
}
