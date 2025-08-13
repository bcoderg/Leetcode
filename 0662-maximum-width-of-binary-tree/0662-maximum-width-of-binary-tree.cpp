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
    int widthOfBinaryTree(TreeNode* root) {
        int mx = 0;
        queue<pair<TreeNode* , int>>q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            int startIdx = q.front().second;
            int endIdx = q.back().second;

            mx = max(mx , endIdx - startIdx + 1);

            for(int i=0;i<sz;i++)
            {
                auto [node,idx] = q.front();
                q.pop();

                if(node->left!=nullptr)q.push({node->left , (long long)2*idx + 1});
                if(node->right!=nullptr)q.push({node->right , (long long)2*idx + 2});
            }
        }
        return mx;
    }
};