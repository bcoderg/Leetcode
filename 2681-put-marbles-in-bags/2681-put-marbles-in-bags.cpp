class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<long long>pairWeights(n-1,0);
        for (int i = 0; i < n - 1;i++){
            pairWeights[i]=weights[i]+weights[i+1];
        }
        sort(pairWeights.begin() , pairWeights.end());
        long long minScore=0;
        long long maxScore=0;
        for(int i=0;i<k-1;i++)
        {
            minScore+=pairWeights[i];
            maxScore+=pairWeights[n-2-i];
        }
        return maxScore-minScore;
    }
};