class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxCnt = 0 , cnt = 0 , maxVal = 0;
        for(int num: nums){
            if(num==maxVal){
                cnt++;
            }else if(num>maxVal){
                maxVal = num;
                cnt=1;
                maxCnt = 0; //if we find any new value set the ans = 0
            }
            else{//missed this else block earlier
                cnt = 0;
            }
            maxCnt = max(maxCnt , cnt);
        }
        return maxCnt;
    }
};