class Solution {
public:
    char kthCharacter(int k) {
        string s="a";

        auto getGenString = [&](string s)->string{
            string cur=s , new_str = s;
            for(int i=0;i<new_str.size() ; i++){
                if(new_str[i]=='z'){
                    new_str[i]='a';
                }
                else{
                    new_str[i] = new_str[i] + 1;
                }
            }
            cout<<cur<<" "<<new_str<<"\n";
            return cur+new_str;
        };

        while(s.size() < k){
            s = getGenString(s);
        }
        return s[k-1];
    }
};