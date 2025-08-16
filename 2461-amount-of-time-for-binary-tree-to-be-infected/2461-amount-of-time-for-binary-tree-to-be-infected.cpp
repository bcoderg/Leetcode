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
    vector<vector<int>>v; 
    void buildParent(TreeNode* root)
    {
        if(!root)return; 
        if(root->left)
        {
            v[root->val].push_back(root->left->val);
            v[root->left->val].push_back(root->val);
        }
        if(root->right)
        {
            v[root->val].push_back(root->right->val);
            v[root->right->val].push_back(root->val);
        }
        buildParent(root->left);
        buildParent(root->right);
    }
    int get_len(int start_node)
    {
        vector<int>vis(1000000,0);

        queue<int>q;
        q.push(start_node);
        vis[start_node]=1;
        int ans=0 , k=0; 
        while(!q.empty())
        {
            k=max(k,ans);
            ans++;
            int sz=q.size();
            while(sz--)
            {
                auto fr=q.front();q.pop();
                for(auto x:v[fr])
                {
                    if(vis[x])
                    {
                        continue;
                    }
                        q.push(x);
                        vis[x]=1;
                }
            }
        }
        return k;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        //try left height,right height method
        //another O(n) approach
        
        v.assign(1000000 , vector<int>()); 
        buildParent(root);
        int ans = get_len(start);
        return ans;
    }
};