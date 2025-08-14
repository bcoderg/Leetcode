class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0 , r=n-1;
        while(l<r){
            int m=l+(r-l)/2; 
            if(nums[m]>nums[r]){
                l=m+1;
            }
            else{
                r=m;
            }
        }
      //0 1 2 3 4
        // 3 4 5 1 2
        // l   m   r 
        //       l r 
        return nums[l];
    }
};