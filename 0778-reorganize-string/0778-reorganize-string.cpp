class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int mx=0;
        char maxFreqChar;
        for(char &c:s){
            mp[c]++;
            if(mp[c]>mx){
                mx=mp[c];
                maxFreqChar=c;
            }
        }
        if(mx > (n+1)/2 )return "";
        int idx=0;
        string ans(n , ' ');

        while(mp[maxFreqChar]>0){
            ans[idx]=maxFreqChar;
            mp[maxFreqChar]--;
            idx+=2;
        }
        for(auto x:mp){
            if(x.first == maxFreqChar)continue;
            int freq=x.second;
            while(freq > 0){
                if(idx>=n)idx=1;
                ans[idx]=x.first;
                idx+=2;
                freq--;
            }
        }
        return ans;
    }
};