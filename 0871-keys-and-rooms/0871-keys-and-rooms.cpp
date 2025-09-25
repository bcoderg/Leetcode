class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int roomNo = q.front();
            q.pop();

            for(int key: rooms[roomNo]){
                if(!vis[key]){
                    vis[key] = 1;
                    q.push(key);
                }
            }
        }
        int sum = accumulate(begin(vis) , end(vis) , 0);
        return sum == n;
    }
};