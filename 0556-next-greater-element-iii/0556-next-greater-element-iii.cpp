class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int size = s.size();
        int i = size - 1, j = size - 1;
       
        // Step 1: Find first decreasing digit from right
        while (i > 0 && s[i] <= s[i - 1]) {
            i--;
        }

        if (i == 0) return -1; // Already the largest permutation

        while (s[j] <= s[i-1])j--;

        swap(s[i-1] , s[j]);
        sort(s.begin() + i , s.end());
        long long res=stoll(s);
        if(res<=INT_MAX)return (int)res;

        return -1;
    }
};