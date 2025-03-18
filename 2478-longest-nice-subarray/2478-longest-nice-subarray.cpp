class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0 , x=0;
        int l=0;
        for(int r=0;r<n;++r)
        {
            while( (x&nums[r]) != 0)
            {
                x=x^nums[l];
                l++;
            }
            x |= nums[r];
            ans=max(ans,r-l+1);
        }
        return ans;      
    }
};




