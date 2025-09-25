class Solution {
public:
string s;
    int check(int i,int j)
    {
        int ans=0;
        while(i>=0 && j<=s.size() && s[i--]==s[j++])ans++; 

        return ans;
    }
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        this->s = s;
        /*
        for(int i = 0; i < n; i++)
        {
            ans += check(i,i);    // odd length palindromes
            ans += check(i,i+1); // even length palindromes
        }
        return ans;
        */

        //DP grid filling appraoch
        vector<vector<bool>>dp(n , vector<bool>(n, false));
        for(int i = 0 ; i < n ; i++)
        {
            dp[i][i] = true;
            for(int j = 0 ;j < i; j++)
            {
                if(s[i]==s[j] && (i-j <=2 || dp[j+1][i-1] ) ){
                    dp[j][i]=true;
                    ans++;
                }
            }
        }
        ans+=s.size();
        return ans;
    }
};