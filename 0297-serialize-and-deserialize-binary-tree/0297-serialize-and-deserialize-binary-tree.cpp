
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    const string NULLNODE = "N";
    const char DELIM = ',';

    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return NULLNODE + string(1,DELIM);
        }

        return to_string(root->val) + DELIM + serialize(root->left) + serialize(root->right);
    }
    
    TreeNode* buildTree(stringstream &ss){
        string token;
        getline(ss,token,DELIM);// , is delimiter

        if(token==NULLNODE){
            return nullptr;
        }
        
        TreeNode *node = new TreeNode(stoi(token));
        node->left = buildTree(ss);
        node->right = buildTree(ss);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildTree(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));