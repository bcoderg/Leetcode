//Make AC & submit it
class Solution {
    vector<string>comb;
    string mp[10]={"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void rec2_function(int index , string digits ,string currcomb)
    {
        if(index >= digits.size())
        {
            comb.push_back(currcomb);
            return;
        }
        /*
        int val=digits[index] - '0';
        string x=mp[val];
        for(int i=0;i<x.size();i++)
        {
            // temp.push_back(x[i]);
            // rec_function(index+1,digits);
            // temp.pop_back();
            rec2_function(index+1,digits,currcomb+x);
        }
        */

        for(auto p:mp[digits[index]-'0'])
        {
            rec2_function(index+1,digits,currcomb+p);
        }

       
    }

public:
    vector<string> letterCombinations(string digits) {
        int index=0;
        

         if(digits.size()==0)return comb;

        rec2_function(index,digits,"");
        return comb;
    }
};


    // string mp[10]={"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    //                 0      2      3      4      5       6       7     8        9 



















