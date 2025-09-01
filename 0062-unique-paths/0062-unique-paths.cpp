class Solution {
public:
    int uniquePaths(int m, int n) {
        /*vector<vector<int>>dp(m , vector<int>(n,1));
        //robo moves bottom or right 
        //for each cell , pick values from top,left 
        vector<int>pre(n,1);

        for(int i=1;i<m;i++){
            // vector<int>cur(n,1);
            for(int j=1;j<n;j++){
                // cur[j] = (pre[j] + cur[j-1]); //pre[j] is cur[j] in pev step, we can reuse
                pre[j] += pre[j-1];
            }
        //  pre = cur;
         }
        return pre[n-1];*/

        //better approach than O(m*n) , is using combinatorics
        //m-1 downs , n-1 rights are needed
        //represent all possible ways using nCr formula
        // if(m>n){
        //     swap(m,n);//to minimise nCr calculation steps
        // }
        //nCr = n! / (n-r)! * r! 
        double res=1;
        int r = m-1;
        int N = n + m - 2;
        for(int i=1;i<=r;i++){
            res = res * (N - r + i)/i; 
        }
        return (int)res;
    }
};