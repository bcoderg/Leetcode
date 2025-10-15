class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int curInc = 1 , prevInc = 0 , res = 0;

        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                curInc++;
            }
            else{
                prevInc = curInc ; 
                curInc = 1;
            }

            int curLen = max(curInc/2 , min(curInc , prevInc) );
            res = max(res , curLen);
        }
        return res;
    }
};