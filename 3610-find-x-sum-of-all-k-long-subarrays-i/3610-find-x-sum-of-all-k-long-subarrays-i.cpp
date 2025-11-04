class Solution {
public:
    typedef pair<int,int> P;  

    int getXSum(unordered_map<int,int>&mp , int x){
        // efficient - maintain PQ of size x - use min heap to pop smaller ones  

        priority_queue<P , vector<P> , greater<P> > pq;
        for(auto [val, freq] : mp){
            pq.push({freq , val});

            if(pq.size() > x){
                pq.pop();
            }
        }

        int xsum = 0;
        while(!pq.empty()){
            auto [freq , val] = pq.top();
            pq.pop();

            xsum += (freq * val);
        }
        return xsum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int , int>mp; 
        vector<int>ans;

        int i =0 , j = 0;
        while(j < n ){

            mp[nums[j]]++; 

            if(j - i + 1 == k){
                int xsum = getXSum(mp , x);
                ans.push_back(xsum);

                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};