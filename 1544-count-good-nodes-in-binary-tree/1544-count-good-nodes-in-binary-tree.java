/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int cnt;
    void dfs(TreeNode root , int curMax){
        if(root==null)return; 

        int curVal = root.val;
        if(curMax<= curVal){
            cnt++; //found good node
        }
        dfs(root.left , Math.max(curMax , curVal));
        dfs(root.right , Math.max(curMax , curVal));
    }
    public int goodNodes(TreeNode root) {
        cnt = 0;
        int curMax = root.val;
        dfs(root , curMax);
        return cnt;
    }
}