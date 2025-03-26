class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rem=grid[0][0]%x;
        vector<int>nums;
        int total=0;
        for(auto row:grid){
            for(auto num:row){
                int curRem=num%x;
                if(rem!=curRem)return -1; 
                nums.push_back(num);
                total+=num;
            }
        }
        int res=INT_MAX;
        sort(nums.begin() , nums.end());
        int n=nums.size();
        //A1
        // int pre=0;
        // for(int i=0;i<n;i++){
        //     int costLeft=nums[i]*i - pre;
        //     int costRight=total-pre - (nums[i]*(n-i));
        //     int steps=(costLeft+costRight)/x;
        //     pre+=nums[i];
        //     res=min(res,steps);
        // }
        //return res;

        //A2
        int median=nums[n/2];
        res=0;
        for(int n:nums){
            res+=(abs(median-n)/x);
        }
        return res;
    }
};