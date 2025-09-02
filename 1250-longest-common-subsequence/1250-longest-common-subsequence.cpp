class Solution {
public:
    vector<vector<int>>dp;
    int lcs(string &s1 , string &s2 , int i , int j )
    {
        if (i == 0 || j == 0){
            return dp[i][j] = 0;
        }
        if (dp[i][j] != -1)return dp[i][j];

        int ans = 0;
        if (s1[i-1] == s2[j-1]) {
            ans = 1 + lcs(s1, s2, i - 1, j - 1 );
        }
        else {
            ans = max( lcs(s1, s2, i - 1, j )  , lcs(s1, s2, i, j - 1 ) );
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int longestCommonSubsequence(string s1, string s2) {
        int n =  s1.size() , m = s2.size();
        dp.assign(n+1  , vector<int>(m+1 , -1) );
        return lcs(s1, s2, n, m);
    }
};
