class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxTriplet = 0 , maxDiff = 0 , maxValue=0;
        for(long long num:nums)
        {
            maxTriplet = max(maxTriplet , maxDiff*num);
            maxDiff = max(maxDiff , maxValue - num);
            maxValue = max(maxValue , num);
        }
        return maxTriplet;
    }
};