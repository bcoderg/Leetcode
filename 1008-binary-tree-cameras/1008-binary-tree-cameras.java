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
    int res=0;
    int COVERED=2;
    int LEAF = 0;
    int HAS_CAMERA = 1; 
    int dfs(TreeNode root){
        if(root==null)return COVERED;

        int left=dfs(root.left) , right = dfs(root.right);

        if(left==LEAF || right==LEAF){
            res++;
            return HAS_CAMERA;
        }

        if(left==HAS_CAMERA || right==HAS_CAMERA){
            return COVERED;
        }
        return LEAF;
    }
    public int minCameraCover(TreeNode root) {
        //greedy have cameras on nodes which are parents of leaf
        return (dfs(root) ==0 ? 1:0) + res;
    }
}
