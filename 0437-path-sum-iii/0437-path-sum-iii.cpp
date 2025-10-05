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
    unordered_map<long long int, long long int>mp;
    int f(TreeNode* root , long long int curSum , int targetSum){
        if(!root)return 0;

        curSum += root->val;
        int res = mp[curSum - targetSum]; //if any gets added 
        mp[curSum]++;
        res += f(root->left,curSum , targetSum);
        res += f(root->right,curSum , targetSum);

        //restore after recursion, minus as in other paths this val is not included
        mp[curSum]--;
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        mp[0] = 1;
        return f(root,0,targetSum);     
    }
};