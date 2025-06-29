class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int c = 0;
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
    
        //precompute 2 powers 
        vector<long long int>power(n);
        power[0]=1;
        for(int i=1;i<n;i++)
        {
            power[i]=(2 * power[i-1])%mod;
        }

        int l=0,r=n-1;
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                int diffIdx=r-l;
                c = (c + power[diffIdx] )%mod;
                l++;
            }
            else{
                r--;
            }
        }
        return c;
    }
};

// target=10
// 3 3 6 8
// 33
// 36
// 36
// 336
// 3
// 3

