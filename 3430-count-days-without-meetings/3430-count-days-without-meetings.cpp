class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin() , meetings.end());
        int noMeetingDaysCount=0;
        int end=0;
        int n=meetings.size();
        for(int i=0;i<n;i++){
            if(meetings[i][0]>end){
                noMeetingDaysCount+=(meetings[i][0]-end-1);
            }
            end=max(end,meetings[i][1]);
        }
        noMeetingDaysCount+=(days-end);
        return noMeetingDaysCount;
    }
};