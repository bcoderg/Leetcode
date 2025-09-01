class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m , vector<int>(n,1));
        //robo moves bottom or right 
        //for each cell , pick values from top,left 
        vector<int>pre(n,1);

        for(int i=1;i<m;i++){
            vector<int>cur(n,1);
            for(int j=1;j<n;j++){
                cur[j] = (pre[j] + cur[j-1]);
            }
            pre = cur;
        }
        return pre[n-1];
    }
};