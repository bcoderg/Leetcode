class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int oneCount = count(begin(nums) , end(nums) , 1);
        if(oneCount > 0){
            return n - oneCount;
        }

        int minLen = INT_MAX;
        //min steps to reach gcd 1 
        for(int i=0;i<n-1;i++){
            int gcdVal = nums[i];

            for(int j=i+1;j<n;j++){
                gcdVal = __gcd(gcdVal , nums[j]);

                if(gcdVal == 1){
                    minLen = min(minLen , j - i);
                    break;//reached 1
                }
            }
        }

        if(minLen == INT_MAX)return -1;

        return (n - 1) + minLen;
    }
};