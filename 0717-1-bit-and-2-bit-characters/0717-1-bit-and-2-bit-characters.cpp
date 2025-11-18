class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        
        int prevIdx = -1 , i = 0;
        while(i < n-1 ){
            if(bits[i]==1){
                i += 2; // consider as 2 bit
            }
            else{
                i += 1;
            }
        }
        return i == n - 1;
    }
};