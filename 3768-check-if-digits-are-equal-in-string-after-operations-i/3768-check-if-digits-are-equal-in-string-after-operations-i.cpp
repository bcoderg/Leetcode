class Solution {
public:
    string getUpdatedString(string s){
        string x; 
        for(int i=0;i<s.size() - 1;i++){
            int newChar = ( s[i]-'0' + s[i+1]-'0' )%10;
            x += to_string(newChar);
        }
        return x;
    }
    bool hasSameDigits(string s) {
        if(s.size()==2){
            return s[0]==s[1];
        }
        string newString = getUpdatedString(s);
        return hasSameDigits(newString);
    }
};