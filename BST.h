#ifndef __BST_H__
#define __BST_H__

enum ETraverseMode
{
	eInOrder,
	ePreOrder,
	ePostOrder
};

struct TreeNode
{
	int 		m_data;
	TreeNode*	m_left;  // Smaller than root
	TreeNode*	m_right; // Bigger than root
};

typedef void(*PrintFunc)(TreeNode*);


TreeNode* 	BuildBST();
void		DestroyBST(TreeNode** root);
void 		InsertNode(TreeNode** root, TreeNode* newNode);
void        	InsertNode(TreeNode** root, int val);
void		PrintInOrder(TreeNode* root);
void		PrintPreOrder(TreeNode* root);
void		PrintPostOrder(TreeNode* root);
void 		PrintBST(TreeNode* root, PrintFunc func = PrintInOrder);
void        	removeNode(TreeNode **root ,int val);
int         	getDepth(TreeNode* root);
bool        	isExists(TreeNode* root , int val);
bool        	isEqual(TreeNode* root1,TreeNode* root2) ;

#endif // __BST_H__
