class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals) , end(intervals));
        int st=intervals[0][0] , end=intervals[0][1];
        vector<vector<int>>v;
        int n=intervals.size();
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>end){
                v.push_back({st,end});
                st=intervals[i][0];
                end=intervals[i][1];
            }
            else{
                end=max(end , intervals[i][1]);
            }
        }
        v.push_back({st,end});
        return v;
    }
};