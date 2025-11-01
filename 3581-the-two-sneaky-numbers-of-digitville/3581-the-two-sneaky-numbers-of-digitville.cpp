class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        //bitwise XOR approach
        /*
        int totalXor = 0;
        for(auto &x:nums){
              totalXor ^= x;
        }

        int n = nums.size() - 2;
        for(int i=1;i<n;i++){
              totalXor ^= i;
        }

        int lsb = totalXor & ( - totalXor); // least significant bit 

        int xor1 = 0 , xor2 = 0;
        for(auto &x:nums){
              if(x & lsb){
                     xor1 ^= x;
              }
              else{
                     xor2 ^= x;
              }
        }

        //iterate over 1 to n , to remove single elements 
        for(int i=1;i<n;i++){
              if(i & lsb){
                     xor1 ^= i;
              }
              else{
                     xor2 ^= i;
              }
        }
        return {xor1 , xor2};
        */

        //to handle 0 - trick incr all by 1 , add val-1 to our answer
        for(auto &x:nums){//incr by 1
            x += 1;
        }

       //use indices - mark values as negative approach 
       vector<int>ans;
       for(int i = 0 ; i < nums.size() ; i++)
       {
              int val = abs(nums[i]);
              if(nums[val] < 0){
                     ans.push_back(val-1);
              }
              else{
                     nums[val] *= -1;
              }
       }
    
       for(auto &x:nums){ // agian decr back by 1 - to keep data unchanged
            x -= 1;
        }

       return ans;
    }
};