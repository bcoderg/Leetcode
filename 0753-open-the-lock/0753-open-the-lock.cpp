class Solution {
public:
    vector<string> getNextLocks(string& source) {
        vector<string>v;

        for (int i = 0 ; i < 4 ; i++) {
            for (int delta : { -1 , 1}) {
                string neighbour = source;

                neighbour[i] = '0' + (source[i] - '0' + delta + 10) % 10;
                v.push_back(neighbour);
            }
        }
        return v;
    }


    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>deadEndsSet(deadends.begin() , deadends.end());
        string source = "0000";
        if (deadEndsSet.count(source))return -1;

        if (source == target)return 0;

        //lock state , no.of moves
        queue<pair<string , int> >q;
        unordered_set<string>vis;
        vis.insert(source);
        q.push({source , 0});

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            string curLock = cur.first;
            int curMoves = cur.second;

            vector<string> nextLocks = getNextLocks(curLock);
            for (string &s : nextLocks) {
                if (!vis.count(s) && !deadEndsSet.count(s)) {
                    if (s == target)return curMoves + 1;

                    vis.insert(s);
                    q.push({s , curMoves + 1} );
                }
            }
        }
        return -1;
    }
};