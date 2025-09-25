class Solution {
public:
    int numTrees(int n) {
        //recursion , can memoize it 
        // if(n==0 || n==1)return 1; 
        // int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     ans += ( numTrees(i) * numTrees(n - i - 1) );
        // }
        // return ans;

        //tabulation
        vector<int>count(n+1,0);
        count[0] = count[1] = 1;

        for(int idx=2 ; idx<=n ; idx++){
            for(int i=0 ; i<idx ; i++){
                count[idx] += (count[i] * count[idx-i-1] );//here idx acts as n
            }
        }
        return count[n];
    }
};