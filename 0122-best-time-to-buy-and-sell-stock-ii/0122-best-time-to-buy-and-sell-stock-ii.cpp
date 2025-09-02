class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //can do a dp approach - each day option of buy/sell 
        //sell after buy , new buy after a prev sell 

        //greedy - O(n)
        //consider ups and downs as peak(up), valley(down)
        //total profit = (peak - valley)
        //if inc peak 1-2-3-6 = (6-1) = 5 profit 
        //above same as individual peaks (2-1) + (3-2) + (6-3) = 5 profit 

        int ans = 0;
        for(int i=1;i<prices.size();i++){
            ans += max(0 , prices[i] - prices[i-1]);
        }
        return ans;
    }
};