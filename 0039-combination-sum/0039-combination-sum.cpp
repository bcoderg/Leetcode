class Solution {
    vector<vector<int>>ans;
    void findComb(int idx,vector<int>&candidates,int target,vector<int>vec)
    {
        if(target==0){
            ans.push_back(vec);return;//base case
        }
        if(target<0 || idx==candidates.size())return;//invalid case
        
        for(int i=idx;i<candidates.size();i++){
            vec.push_back(candidates[i]);
            findComb(i,candidates,target-candidates[i],vec);//stay at i index only, we can reuse same element
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>vec;
        sort(candidates.begin(), candidates.end());
        findComb(0,candidates,target,vec);
        return ans;
    }
};