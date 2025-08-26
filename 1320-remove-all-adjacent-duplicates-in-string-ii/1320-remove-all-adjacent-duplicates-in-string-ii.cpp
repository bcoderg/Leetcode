class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        vector<pair<int,char>>stk = {{0,'#'}};
        for(char c:s){
            if(stk.back().second != c){
                stk.push_back({1,c});
            }
            else{//same char as prev
                ++stk.back().first;
                if(stk.back().first==k){//k consecutive character
                    stk.pop_back();
                }
            }
        }
        string res;
        for(auto [count,character]: stk){
            res.append(count , character);
        }
        return res;
    }
};