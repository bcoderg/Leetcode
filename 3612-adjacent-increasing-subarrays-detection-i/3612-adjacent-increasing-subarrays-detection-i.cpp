class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0 , curInc = 1 , prevInc = 0; 
        for(int i = 1 ; i < n ; i++){
            if(nums[i] > nums[i-1]){
                curInc++;
            }
            else{
                prevInc = curInc;//update previous increase value
                curInc = 1;
            }

            int maxIncLen = max(curInc/2 , min(prevInc , curInc) );
                        //current Increasing divided to two parts , min of both increase 

            res = max(res ,  maxIncLen);
        }
        return res >= k;
    }
};