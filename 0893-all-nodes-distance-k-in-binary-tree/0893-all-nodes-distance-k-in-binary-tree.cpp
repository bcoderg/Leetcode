/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*>parent;
    vector<int>res;
    void inorder(TreeNode* root, TreeNode* par){
        if(!root)return;

        if(par!=NULL){
            parent[root] = par;
        }
        inorder(root->left,root);
        inorder(root->right,root);
    }

    void dfs(TreeNode* root, TreeNode* par , int k)
    {
        if(!root || root==par)return;
        if(k==0){
            res.push_back(root->val);
            return;
        }
        if(root->left != par)dfs(root->left,root,k-1);
        if(root->right != par)dfs(root->right,root,k-1);
        TreeNode* parentNode = parent[root];
        if(parentNode != par)dfs(parentNode,root,k-1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inorder(root,NULL);
        dfs(target,NULL,k);
        return res;
    }
};