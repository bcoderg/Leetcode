class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)return 0; 

        int c = 0;
        int l = 0 , r = 0 , n = nums.size();
        long long int p = 1;
        while(r<n){
            p *= (long long int)nums[r];

            while(l<=r && p >= k){
                p /= nums[l];
                l++;
            }

            c += r - l + 1;
            r++;
        } 
        return c;
    }
};