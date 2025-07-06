class Solution {
public:
    int findLucky(vector<int>& arr) {
        //O(1) space approach
        //approach 1 - encoding storing both value , frequency 
        //32 bits - first 16 bits - stores value
        //next 16 bits store frequency 
        int n=arr.size();
        int encodeVal = 1<<16;

        for(int &num:arr){
            int val = num & (encodeVal - 1);

            if(val<=n){
                arr[val-1] += encodeVal;
            }
        }

        for(int val=n ; val>=1; val--)
        {
            if(arr[val-1]>>16 == val){//freq == val
                return val;
            }
        }
        return -1;
    }
};