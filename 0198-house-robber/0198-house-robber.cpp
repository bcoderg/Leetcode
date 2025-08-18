class Solution {
public:
vector<int>dp;
//memo
// int fun(int idx , vector<int>&v)
// {
// 	if(idx>=v.size())return 0;
// 	if(dp[idx]!=-1)return dp[idx];
	
// 	int pick=v[idx] + fun(idx+2 , v); 
// 	int notpick=fun(idx+1,v); 
// 	return (dp[idx]=max(pick , notpick) );
// }

	int rob(vector<int>& v) { 
		int n=v.size();
		dp.assign(n+1,0);
		//return fun(0,v);
		//bottom up 1D DP
		// for(int i=1;i<=n;i++)
		// {
		// 	int pick = v[i-1];
		// 	if(i>1)pick += dp[i-2];
		// 	int notpick = dp[i-1];
		// 	dp[i] = max(pick , notpick);
		// }
		// return dp[n];
		
		//1D DP with space optimization
		int prev2=0, prev1=0;
		for(int i=0;i<n;i++)
		{
			int pick = v[i] + prev2; //prev2 is i-2th index 
			int notpick = prev1; //if cur not pick , then prev1 is i-1th index 
			
			int curMax = max(pick , notpick);
			//prev1 will be new prev2
			prev2 = prev1;
			//curMax will be new prev1
			prev1 = curMax;
		}
		return prev1;
	}
};