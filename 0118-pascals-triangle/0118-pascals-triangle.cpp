class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        res.push_back({1});
        if(numRows==1)return res;
        res.push_back({1,1});

        for(int i=2; i<numRows; i++)
        {
            int prevIndex = i-1;
            vector<int>curRow;
            curRow.push_back(1);//first 1
            vector<int>& prevRow = res.back();
            for(int j=0; j<i-1; ++j){
                curRow.push_back(prevRow[j] + prevRow[j+1]);
            }
            curRow.push_back(1);//last 1
            res.push_back(curRow);
        }
        return res;
    }
};