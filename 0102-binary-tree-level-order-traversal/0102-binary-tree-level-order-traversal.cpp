/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)return {};
        if(root->left==nullptr && root->right==nullptr)return {{root->val}};

        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
          int sz=q.size();
          vector<int>v;
          for(int i=0;i<sz;i++){
            TreeNode* f = q.front();
            q.pop();
            v.push_back(f->val);
            if(f->left!=nullptr)q.push(f->left);
            if(f->right!=nullptr)q.push(f->right);
          }
          ans.push_back(v);
        }

        return ans;
    }
};