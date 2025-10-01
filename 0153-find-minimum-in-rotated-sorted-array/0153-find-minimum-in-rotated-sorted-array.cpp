class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0 , r=n-1;
        int mn = INT_MAX;
        while(l<= r){//standard BS type , track min value
            int m=l+(r-l)/2; 
            
            //minor optimisation(can ignore as well)
            if(nums[l]<=nums[r]){
                mn = min(mn , nums[l]);
                break;
            }

            if(nums[l] <= nums[m]){
                mn = min(mn , nums[l]);
                l = m+1;
            }
            else{
                mn = min(mn , nums[m]);
                r = m - 1;
            }
        }
        return mn; 
      //0 1 2 3 4
        // 3 4 5 1 2
        // 
    }
};