class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        //for O(1) space , let's reuse the existing array by swapping numbers to their positons 
        //index -> 0 to n-1 
        //set number i , in i-1th index  
        for(int i=0;i<n; i++){
            while(nums[i]>0 && nums[i]<=n && nums[i] != nums[nums[i]-1]){
                swap(nums[i] , nums[nums[i]-1]);
            }
        }

        //after all swaps first index where  nums[i] != i+1 is answer 
        for(int i=0;i<n;i++){
            if(nums[i] != i+1)
                return i+1;
        } 
        return n+1;//if all n correct , n+1 is ans
    }
};

