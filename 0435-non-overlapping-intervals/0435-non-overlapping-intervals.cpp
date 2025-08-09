class Solution {
public:
    static bool cmp(vector<int>&a , vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);
        int maxEndTime=v[0][1];
        int cnt=1;
        for(int i=1;i<v.size();i++){
            //if cur start time>= maxEndTime ==> valid
            if(v[i][0] >= maxEndTime){
                cnt++;
                maxEndTime = v[i][1];
            }
        }
        return v.size()-cnt;
    }
};