class Solution {
public:
    int possibleStringCount(string word) {
        int c=1 , n=word.size();
        for(int i=0;i<n;i++)
        {
            
            if(word[i]==word[i+1])
            {
                int cnt=0;
                int j=i+1;
                while(word[i]==word[j]){
                    cnt++;
                    j++;
                }
                c+=cnt;
                i=j-1;
            }
        }
        return c;
    }
};