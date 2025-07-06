class Solution {
public:
  vector<int>dp;
  int getNextIndex(vector<vector<int>>&v , int l , int curJobEnd) {
    int r = v.size() - 1;
    int res = v.size();
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (v[mid][0] >= curJobEnd) {
        res = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    return res;
  }
  
  int f(vector<vector<int>>&v , int index)
  {
    int n = v.size();
    if (index >= n)return 0;

    if (dp[index] != -1)return dp[index];

    int nextIndex= getNextIndex(v , index + 1 ,  v[index][1]);
    int take = v[index][2] + f(v, nextIndex);
    int notTake = f(v, index + 1);

    return dp[index] = max(take , notTake);
  }
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    dp.assign(n + 1 , -1);

    vector<vector<int>>jobs(n , vector<int>(3));
    for (int i = 0; i < n; i++) {
      jobs[i][0] = startTime[i];
      jobs[i][1] = endTime[i];
      jobs[i][2] = profit[i];
    }
    sort(jobs.begin() , jobs.end());
    return f(jobs, 0);
  }
};