class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int c = 0;
        for(auto &x: nums){
            if(x % 3 != 0){
                c++;//always do min step 
                //if rem 1 = -1 
                //if rem 2 = +1
            }
        }
        return c;
    }
};