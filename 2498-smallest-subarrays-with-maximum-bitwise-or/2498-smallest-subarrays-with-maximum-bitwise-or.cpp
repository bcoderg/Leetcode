class Solution {
public:
    void updateSetBits(int num, int idx, vector<int>&setBitIndex){
            int k = 0;
            while(k<32){
            //if exceed return
            if( (1<<k) > num)return; 

            if(num&(1<<k)){
                setBitIndex[k] = idx;
            }
            k++;
            }
    }

    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int>ans(n);
        vector<int>setBitIndex(32,-1);
        int num = nums[n-1];

        //updateSetBits(nums[n-1] , n-1 ,  setBitIndex);

        for(int i=n-1; i>=0 ; i--)
        {
            updateSetBits(nums[i] , i , setBitIndex);
            int maxIndex = *max_element(begin(setBitIndex) , end(setBitIndex));
            int len = maxIndex - i + 1;
            //cout<<"mx = "<<maxIndex<<" ,i = "<<i<<"len = "<<len<<"\n";
            if(len<=0)len=1;
            ans[i] = len;
        }

        // for(int i=0;i<32;i++){
        //     cout<<" i = "<<i<<" "<<setBitIndex[i]<<"\n";
        // }
        return ans;
    }
};