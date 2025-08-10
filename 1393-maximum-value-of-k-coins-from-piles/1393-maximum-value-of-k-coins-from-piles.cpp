class Solution {
public:
    vector<vector<int>>memo;
    int f(int idx , int k , vector<vector<int>>& v , vector<vector<int>>&memo){
        if(idx>=v.size() || k==0)return 0;
        if(memo[idx][k]!=-1)return memo[idx][k];

        int notTakeThisPile = f(idx+1,k,v,memo);
        int takeThisPile=0 , cur=0;
        for(int j=0 ; j<v[idx].size() && j<k; j++)
        {
            cur+= v[idx][j];//add coin amount to cur
            //can take any no.of coins from this pile
            // so take check in loop
            takeThisPile = max(takeThisPile , cur + f(idx+1,k-j-1,v,memo) );
        }
        return memo[idx][k] = max(takeThisPile , notTakeThisPile);
    }
    int maxValueOfCoins(vector<vector<int>>& v, int k) {
        int n=v.size();
        memo.assign(n+1 , vector<int>(k+1, -1) );
        return f(0,k,v,memo);
    }
};