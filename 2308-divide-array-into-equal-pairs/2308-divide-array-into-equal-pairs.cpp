class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        int pairs=n/2;
        map<int,int>mp;
        for(auto x:nums)mp[x]++;
        for(auto x:mp){
            if(x.second%2!=0)return false;
        }
        return true;
    }
};