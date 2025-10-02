class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        //int jumps=0;
        //to have min jumps , let's track the range,farthest we can reach
        /*
        int l=0,r=0;
        while(r<n-1){
            int farthestJump = l;
            for(int i=l;i<=r;i++){//tracking farthest jump from l - r range
                farthestJump = max( i + nums[i] , farthestJump);
            }
            l = r+1;
            r = farthestJump;
            jumps++;
        }
        return jumps;
        //TC: O(N) + O(N)(worst case)
        */

        //APP2 - track curEnd , curFarthest 
        //TC: O(N) always 
        int jumps = 0;
        int curEnd = 0 , curFarthest = 0;
        for(int i=0;i<n-1;i++){

            curFarthest = max( i + nums[i] , curFarthest);

            if(i==curEnd){//cur index is maxEnd , so need new jump
                jumps++;
                curEnd = curFarthest;
            }
        }
        return jumps;
    }
};