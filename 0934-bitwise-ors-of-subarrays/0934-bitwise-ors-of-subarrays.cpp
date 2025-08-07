class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>prev , res;
        for(int &num: arr){
            unordered_set<int>cur;
            for(const int &x:prev){
                cur.insert(x | num);
                res.insert(x | num);
            }
            cur.insert(num);
            res.insert(num);

            //cur will be the prev in next iteration
            prev = cur;
        }
        return (int)res.size();
    }
};