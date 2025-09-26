class Solution {
public:
int fun(string s, int i ,  vector<int>&dp)
{
    int count=0; 

    if(i==s.size())return 1;
    //if(i>s.size())return 0; 

    
    if(dp[i]!=-1)return dp[i];

    count=fun(s,i+1,dp);

    if( (i+1 <s.length() ) && (  (s[i]=='1' || (s[i]=='2' && s[i+1]<='6') ) ) )
    {
        count+=fun(s,i+2,dp);
    }

   return (dp[i]=count);
}
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        int n=s.size();
        //vector<int>dp(n+1,-1); 
        //2 - REC + TOP DOWN dp
        //return fun(s,0,dp);
        

        vector<int>dp(n+1,0); 
        dp[n]=1;
        //BOTTOM - UP TABULATION DP
        for(int i=n-1;i>=0;i--)
        {
        	// int one=s[i-1]-'0'; 
        	// if(one>0 && one<=9)dp[i]+=dp[i-1]; 

        	// int two=stoi(s.substr(i-2,2));
        	// if(two>=10 && two<=26)
        	// {
        	// 	dp[i]+=dp[i-2];
        	// }
        if(s[i]=='0'){
            dp[i]=0;
            continue;
        }
        
        int count=dp[i+1];
        if( (i+1 < n ) && (  (s[i]=='1' || (s[i]=='2' && s[i+1]<='6') ) ) )
        {
            count+=dp[i+2];
        }
        dp[i]=count; 
        }
        return dp[0];
    }
};