class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int oddC=0 , evenC=0 , alternatingC=1 , n = nums.size();

        int prevParity = nums[0]%2 ; 
        for(int i =0;i<n ; i++){
            int num=nums[i];

            if(num&1){
                oddC++;
            }
            else{
                evenC++;
            }

            //updating alternatingC
            if(i>0 && ( nums[i]%2 != prevParity) ){
                alternatingC++;
                prevParity = nums[i]%2;
            }
        }
        
        return max({evenC , oddC , alternatingC});
    }
};