class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int s=1 , p = 1 , ans = INT_MIN;
        for(int i=0;i<n;i++){
            p *= nums[i];
            s *= nums[n-i-1];

            ans = max(ans , p );
            ans = max(ans , s);

            if(p == 0)p = 1;
            if(s == 0)s = 1; 
        }
        return ans;
    }
};