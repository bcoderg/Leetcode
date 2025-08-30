class Solution {
    vector<vector<int>>ans;
    void findComb(int idx,vector<int>&candidates,int target,vector<int>vec)
    {
        if(target==0){
            ans.push_back(vec);return;
        }
        if(target<0 || idx==candidates.size())return;
        
        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])continue;//ignore duplicate subset combinatons 
            if(target<0)break;
            vec.push_back(candidates[i]);
            findComb(i+1,candidates,target-candidates[i],vec);//this acts as pick
            vec.pop_back(); //this is not pick
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>vec;
        sort(candidates.begin(), candidates.end());
        findComb(0,candidates,target,vec);
        return ans;
    }
};