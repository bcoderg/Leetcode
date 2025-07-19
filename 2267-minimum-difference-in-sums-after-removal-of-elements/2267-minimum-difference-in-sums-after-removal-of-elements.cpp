class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/3; 
        vector<long long>leftMin(N ,0) , rightMax(N , 0);
        priority_queue<int>maxPq;
        priority_queue<int , vector<int> , greater<int> >minPq;
        long long curSum=0;

        //fill leftMin
        int endIdx = 2*n - 1;
        for(int si = 0 ; si <= endIdx ; si++)
        {
            curSum += nums[si];
            maxPq.push(nums[si]);
            if(maxPq.size() > n)
            {
                curSum -= maxPq.top();
                maxPq.pop();
            }
            leftMin[si] = curSum;
        }

        //fill rightMax
        endIdx = n - 1; 
        curSum = 0;
        for(int si = N-1 ; si >= endIdx ; si--)
        {
            curSum += nums[si];
            minPq.push(nums[si]);
            if(minPq.size() > n)
            {
                curSum -= minPq.top();
                minPq.pop();
            }
            rightMax[si] = curSum;
        }

        //debug
        // for(auto &x: leftMin)cout<<x<<" ";
        // cout<<"\n";
        // for(auto &x:rightMax)cout<<x<<" ";
        // cout<<"\n";

        long long ans = LLONG_MAX;
        endIdx = 2*n - 1; 
        for(int si = n-1 ; si <= endIdx ; si++)
        {
            ans = min(ans , leftMin[si] - rightMax[si+1] );
        }
        return ans;
    }
};