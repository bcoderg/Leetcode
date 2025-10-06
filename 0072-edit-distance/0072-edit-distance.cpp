class Solution {
public:
    /*
    int edit(int n1 , int n2 , string w1, string w2)
    {
        if(n1==0)return n2;
        if(n2==0)return n1; 

        if(w1[n1-1] == w2[n2-1]){
            return edit(n1-1 , n2-1 , w1 , w2);
        }

        return 1 + min( {edit(n1 - 1 , n2 , w1 , w2) , 
                          edit(n1 , n2 - 1 , w1 , w2) , 
                          edit(n1 - 1 , n2 - 1 , w1 , w2) } );
    }
    */
    int minDistance(string word1, string word2) {
        int n = word1.size() , m = word2.size();
        //return edit(n,m,word1,word2);
        vector<vector<int>>dp(n+1 , vector<int>(m+1,0) );
        for(int i=0;i<=n;i++){
            dp[i][0] = i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j] = j;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int mn = 1 + min( {dp[i-1][j],//insert or remove
                                       dp[i][j-1], 
                                       dp[i-1][j-1] } );//replace
                    dp[i][j] = mn;
                }
            }
        }
        return dp[n][m];
    }
};