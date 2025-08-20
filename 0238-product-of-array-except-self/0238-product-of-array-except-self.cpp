class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int val=1;
        //left to right
        for(int i=0;i<n;i++){
            ans[i] = val;
            val*=nums[i];
        }
        val=1;
        for(int j=n-1;j>=0 ; j--){
            ans[j] *= val;
            val*=nums[j];
        }
        return ans;
    }
};