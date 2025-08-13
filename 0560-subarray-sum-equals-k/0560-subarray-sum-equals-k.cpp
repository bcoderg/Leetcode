class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int n = nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=nums[i]+pre[i-1];
        }
        unordered_map<int,int>mp;
        mp[0]=1;//initial 0 sum is possible 
        for(int i=0;i<n;i++){
            int target = pre[i] - k;
            if(mp.find(target)!=mp.end()){
                ans+=mp[target];
            }
            mp[pre[i]]++;
        }
        return ans;
    }
};