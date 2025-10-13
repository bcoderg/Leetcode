class Solution {
public:
    //count freq - using single array
    bool areAnagrams(string s1 , string s2){
        if(s1.size() != s2.size())return false;
        
        vector<int>count(26,0);

        for(auto &x: s1)count[x - 'a']++;
        for(auto &x: s2)count[x - 'a']--;

        for(int &num:count){
            if(num!=0){
                return false;
            }
        }

        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size(); 
        vector<string>res; 

        string prev = "";
        for(int i = 0 ; i < n ; i++){
            string cur = words[i];

            if(!areAnagrams(cur , prev)){
                res.push_back(cur);
                prev = cur;
            }
        }
        return res;
    }
};