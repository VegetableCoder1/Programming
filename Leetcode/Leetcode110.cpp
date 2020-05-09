/*
平衡二叉树 
判断一棵数是不是平衡二叉树

[思路]树型dp  从子树中返回需要的综合信息，然后根据信息组合成这棵树的综合信息传递给父亲节点
需要的信息 左子树高，右子树高，左子树是否为平衡二叉树，右子树是否为平衡二叉树
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int height(TreeNode* root)
{
	if(root == NULL) return 0;
	else
	{
		int left = height(root->left)+1;
		int right = height(root->right)+1;
		return left>right?left:right;
	}
}
bool isBalanced(TreeNode* root)
{
	if(root==NULL) return true;
	bool leftb = isBalanced(root->left);  // 左子树平衡
	bool rightb = isBalanced(root->right);// 右子树平衡
	int left = height(root->left);   // 计算左子树高度
	int right = height(root->right); // 计算右子树高度
	if(abs(left-right)<=1 && leftb && rightb) return true;
	else return false;
}
int main()
{

}