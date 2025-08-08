class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumps=0;
        //to have min jumps , let's track the range,farthest we can reach
        int l=0,r=0;
        while(r < n-1){
            int farthestJump=0;
            for(int i=l;i<=r;i++){
                farthestJump = max( i+nums[i] , farthestJump);
            }
            l=r+1;
            r=farthestJump;
            jumps++;
        }
        return jumps;
    }
};