class Solution {
public:
    int robHouse(int start , int end , vector<int>& v){
        int prev1 = 0 , prev2 = 0;
        for(int i=start ; i<= end ; i++){
            int pick = v[i] + prev2;
            int notpick = prev1; 

            int curMax = max(pick , notpick);

            prev2 = prev1;
            prev1 = curMax; 
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        //0 is connected to n-1 , so pick houses from (0 -> n-2) , (1 -> n-1)
        return max(robHouse(0,n-2,nums) , robHouse(1,n-1,nums));
    }
};