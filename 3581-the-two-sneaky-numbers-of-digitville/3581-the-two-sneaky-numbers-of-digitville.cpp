class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        //bitwise approach
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
         
        //use indices - mark values as negative approach 
    }
};