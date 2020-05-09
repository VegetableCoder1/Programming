/*
另一棵树的子树
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

[思路]将判断融入二叉树的遍历之中
两棵树是否相同，要么是这棵树相同，要么是左子树相同，要么是右子树相同

是否为同一颗树的判断：
该节点相同，左子树相同，右子树相同，即为同一颗子树

对原树的所有节点都要做一次判断，即可返回正确答案
*/

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int main()
{

}

bool isSubtree(TreeNode* s,TreeNode* t)
{
    while(s != NULL)
    {
        if(issame(s,t)) return true;
        return (issame(s->left,s) || issame(s->right,s));
    }
}

bool issame(TreeNode* s,TreeNode* t)
{
    if(s==NULL && t==NULL) return true;
    if(s==NULL || t==NULL) return false;
    if(s->val != t->val) return false;
    return issame(s->left,t->left) && issame(s->right,t->right);
}