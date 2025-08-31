class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int first = cost[0] , second = cost[1];
        for(int i = 2 ; i<n; i++){
            int curCost = cost[i] + min(first , second);
            first = second; 
            second = curCost;
        }
        return min(first,second);
    }
};