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
    TreeNode* get_LCA(TreeNode* root , int a , int b)
    {
        if(!root)return nullptr;

        if(root->val==a || root->val==b)
        {
            return root;
        }
        TreeNode* left=get_LCA(root->left,a,b);
        TreeNode* right=get_LCA(root->right,a,b);
        if(left && right)return root;

        if(left==nullptr)return right; 
        else return left;
    }
    void dfs(TreeNode* root , int val , string &s)
    {
        if(!root)return; 

        if(root->val==val){
            s+="Z";// a temp trigger to state that node is found
            return;
        }
        dfs(root->left,val,s);
        if(s.size()>0)
        {
            s+="L";
            return;
        }

        dfs(root->right,val,s);
        if(s.size()>0)
        {
            s+="R";
            return;
        }
        return;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca=get_LCA(root,startValue,destValue);
        string p1="" , p2=""; 
        dfs(lca,startValue,p1);
        dfs(lca,destValue,p2); 
        reverse(p1.begin(),p1.end());
        reverse(p2.begin(),p2.end());
        string path;
        for(int i=0;i<p1.size()-1;i++)path+="U";
        for(int i=0;i<p2.size()-1;i++)path+=p2[i];
        return path;
    }
};