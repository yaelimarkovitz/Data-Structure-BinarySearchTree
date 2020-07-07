//
// Created by mby on 07/07/2020.
//
#include <iostream>
#include "test.h"
void test_create_print(){
    TreeNode* root = BuildBST();
    std::cout<<"print inorder"<<std::endl;
    PrintBST(root);
    std::cout<<"print preorder"<<std::endl;
    PrintBST(root, PrintPreOrder);
    std::cout<<"print postorder"<<std::endl;
    PrintBST(root, PrintPostOrder);
    InsertNode(&root, 4);
    std::cout<<"print inorder after insert value"<<std::endl;
    PrintBST(root);
    if(isExists(root,11)){
        removeNode(&root,9);
    }
    std::cout<<"print inorder after remove value"<<std::endl;
    PrintBST(root);
    DestroyBST(&root);
    root = NULL;
}

void test_equal_trees(){
    TreeNode* root = BuildBST();
    TreeNode* root2 = BuildBST();
    InsertNode(&root,20);
    std::cout<<"is equal ?"<<std::endl;
    std::cout<<isEqual(root,root2)<<std::endl;
}

void test_remove(){
    TreeNode* root =BuildBST();
    PrintBST(root);

}