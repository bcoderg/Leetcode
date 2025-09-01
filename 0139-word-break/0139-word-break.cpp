class Solution {
public:
    vector<int>dp;
    bool f(int idx , string s , vector<string>&wordDict){

        if(dp[idx]!=-1){
            return dp[idx];
        }

        // if(idx==s.size()){//this base case is covered in dp[s.size()]=1
        //     return true;
        // }

        for(const string& w : wordDict){
            if(idx + w.size() <= s.size() && s.substr(idx , w.size())==w){
                if(f(idx+w.size() , s , wordDict)){
                    return dp[idx] = 1;
                }
            }
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.size()+1 , -1);//1 - true , 0 - false , -1 - not calculated
        dp[s.size()]=1;
        return f(0,s,wordDict);
    }
};