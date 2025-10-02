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
    pair<int,int> f(TreeNode* root){
        if(!root)return {0,0};

        auto [withLeft , withoutLeft] = f(root->left);
        auto [withRight , withoutRight] = f(root->right);

        int withRoot = root->val + withoutLeft + withoutRight;

        int withoutRoot = max(withLeft , withoutLeft) + max(withRight , withoutRight);

        return {withRoot , withoutRoot};
    }
    int rob(TreeNode* root) {
        auto [withRoot , withoutRoot] = f(root);
        return max(withRoot , withoutRoot);
    }
};