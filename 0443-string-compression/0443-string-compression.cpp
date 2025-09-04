class Solution {
public:
    int compress(vector<char>& chars) {
        int  n = chars.size();
        string ans;
        for(int i=0;i<n;i++){
            char cur = chars[i];
            int cnt = 1;
            while(i+1<n && cur == chars[i+1]){
                i++;
                cnt++;
            }
            ans+=cur;
            if(cnt>1)ans+=to_string(cnt);
        }
        for(int i=0;i<ans.size();i++){
            chars[i] = ans[i];
        }
        return ans.size();
    }
};