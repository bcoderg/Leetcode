class Solution {
public:
    vector<vector<int>>memo;
    int M = 1e9 + 7;
    //top down dp - memoization
    /*
    int solve(int i , int count , vector<int>&freq , int k)
    {
        //base case
        if(i>=freq.size()){
            return count < k;
        }

        int result=0;

        if(memo[i][count]!=-1){
            return memo[i][count];
        }

        for(int take=1;take<=freq[i] ; take++)
        {
            if(count + take < k){
                result = ( result + solve(i+1 , count + take , freq , k) )%M;
            }
            else{
                break;
            }
        }

        return memo[i][count] = result;
    }
    */
    int possibleStringCount(string word, int k) {
        int ans = 0 , n = word.size();

        if (k > n)return 0;

        vector<int>freq;
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if (word[i] == word[i - 1]) {
                count++;
            }
            else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);


        //mod functions
        auto modSum = [&](int a , int b)->int{
            return ( (a % M) + (b % M) ) % M;
        };
        auto modProduct = [&](int a , int b)->int{
            return (1LL * (a % M) * (b % M) ) % M;
        };

        auto modSub = [&](int a , int b)->int{
            return ( (a % M) - (b % M) + M ) % M;
        };

        int totalPossibilities = 1;
        for (int &fr : freq) {
            totalPossibilities = modProduct(totalPossibilities , fr);
        }

        n = freq.size();
        if (n >= k)return totalPossibilities;

        memo.assign(n + 1 , vector<int>(k + 1));

        //top down - memoization
        //int invalidPossibilities = solve(0,0,freq,k); //index , count , freq ,


        //bottom up dp - tabulation
        //base case
        for (int count = k - 1; count >= 0; count--) {
            memo[n][count] = 1;
        }

        for (int i = n - 1 ; i >= 0 ; i --)
        {
            //prefix sum
            vector<int>prefix(k + 1, 0);
            for (int h = 1 ; h <= k ; h++)
            {
                prefix[h] = modSum(prefix[h - 1] , memo[i + 1][h - 1]);
            }


            for (int count = k - 1 ; count >= 0 ; count --)
            {
                // int res=0;
                // for(int take = 1 ; take <= freq[i] ; take ++)
                // {
                //     if(count + take < k){
                //         res = ( res + memo[i+1][count+take] )%M;
                //     }
                //     else{
                //         break;
                //     }
                // }
                // memo[i][count]=res;

                //TLE for few cases - bcoz of this inner loop.

                //use prefix sum , avoid this inner loop
                int l = count + 1 , r = count + freq[i];

                if (r + 1 > k) {
                    r = k - 1;
                }

                if (l <= r) {
                    memo[i][count] = modSub(prefix[r+1] , prefix[l]);
                }

            }
        }

        int invalidPossibilities = memo[0][0];
        return modSub(totalPossibilities , invalidPossibilities);
    }
};