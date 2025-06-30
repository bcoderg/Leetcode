class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        
        for(auto &x:nums)mp[x]++;

        int longestHarmonicSubSeqLength=0;
        for(auto &x:mp)
        {
            int key1=x.first;
            int key2=key1+1;

            if(mp.find(key2)!=mp.end())
            {
                int val1=x.second;
                int val2=mp[key2];
                longestHarmonicSubSeqLength=max(longestHarmonicSubSeqLength , val1+val2);
            }
        }
        return longestHarmonicSubSeqLength;
    }
};