class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //we can do BS and insert at right position
        //but still need O(n) to merge 

        //simple fill the answer smartly while checking in O(n)
        vector<vector<int>>res;

        int newIntervalStart = newInterval[0];
        int newIntervalEnd = newInterval[1];
        int i=0 , n=intervals.size();
        
            //non overlapping & before new interval
            while(i<n && intervals[i][1]<newIntervalStart){
                res.push_back(intervals[i]);
                i++;
            }

            //overlapping track update min start , max end time
            while(i<n && intervals[i][0]<=newIntervalEnd){
                newIntervalStart = min(newIntervalStart , intervals[i][0]);
                newIntervalEnd = max(newIntervalEnd , intervals[i][1] );
                i++;
            }
            res.push_back({newIntervalStart , newIntervalEnd});

            //non overlapping at end
            while(i<n){
                res.push_back(intervals[i]);
                i++;
            }
        return res;
    }
};