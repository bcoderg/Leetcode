class Solution {
public:
  int maxEvents(vector<vector<int>>& events) {
    int n=events.size();
    
    sort(events.begin() , events.end());
    priority_queue<int , vector<int> , greater<int>>pq;

    int index = 0, day = events[index][0] , count = 0;

    while (!pq.empty() || index < n)
    {
      if (pq.empty()) {
        day = events[index][0];
      }

      while (index < n && events[index][0] <= day) {
        pq.push(events[index][1]);
        index++;
      }

      if (!pq.empty()) {
        pq.pop();
        count++;
      }
      day++;

      while (!pq.empty() && pq.top() < day) {
        pq.pop();
      }

    }

    return count;
  }
};