class Solution {
public:
    int sz;
    unordered_map<int , int>oneCnt , zeroCnt;

    int memo[101][101][601]; //3d dp m,n,i are states

    int getOneCount(string &s) {
        int one = 0;
        for (char &c : s) {
            if (c == '1')one++;
        }
        return one;
    }
    int f(int idx ,int m , int n){
        if(idx >= sz || (m==0 && n==0) ){
            return 0;
        }

        if(memo[m][n][idx] != -1){
            return memo[m][n][idx];
        }

        int pick = 0;
        if(m >= zeroCnt[idx] && n >= oneCnt[idx]){
            pick = 1 + f(idx+1 , m - zeroCnt[idx] , n - oneCnt[idx]);
        }
        int notPick = f(idx+1 , m , n);

        return memo[m][n][idx] = max(pick , notPick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        //3dp - kanpsack - m,n,i are states 
        sz = strs.size();

        oneCnt.clear();
        zeroCnt.clear();
        
        for (int i = 0; i < sz; i++) {
            int oc = getOneCount(strs[i]);
            int zc = strs[i].size() - oc;

            oneCnt[i] = oc;
            zeroCnt[i] = zc;
        }

        memset(memo , -1 , sizeof(memo));
        return f(0,m,n);
    }
};