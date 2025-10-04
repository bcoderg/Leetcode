class Solution {
public:
    //BS on ans
    bool f(vector<int>& nums, int maxSum ,  int k){
        int sum = 0;
        k--;

        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] <= maxSum){
                sum += nums[i];
            }
            else{
                k--;
                sum = nums[i];
            }
        }
        return k>=0;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(begin(nums) , end(nums));
        int r = accumulate(begin(nums) , end(nums) , 0);

        while(l<=r){
            int m = l + (r-l)/2;
            if(f(nums,m,k)){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};