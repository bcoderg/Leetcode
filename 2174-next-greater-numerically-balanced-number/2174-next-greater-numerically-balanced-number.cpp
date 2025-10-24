class Solution {
public:
    bool isBeautiful(int num){
        vector<int>freq(10 , 0);

        string numStr = to_string(num);
        for(char ch : numStr){
            freq[ch - '0']++;

            if(freq[ch - '0'] > ch - '0')return false;
        }

        for(int i=0;i<10;i++){
            if(freq[i] >0 && freq[i] != i)return false;
        }

        return true;
    }

    int nextBeautifulNumber(int n) {
        int i = n + 1;
        while(!isBeautiful(i)){
            i++;
        }
        return i;
    }
};
