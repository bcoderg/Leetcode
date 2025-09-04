class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        //custom sort pq
        auto cmp = [&](const pair<int,int>&a , const pair<int,int>&b){
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        
        int n1= nums1.size() , n2 = nums2.size();
        vector<vector<int>>ans;

        priority_queue<pair<int,int> , vector<pair<int,int>> , decltype(cmp) >pq(cmp); 
        for(int i=0;i<min(k,n1);i++){
            pq.push({i,0});
        }
        while(k--){
            auto [i , j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i] , nums2[j]});
            if(j+1 < n2){//had syntax error here
                pq.push({i,j+1});
            }
        }
        return ans;
    }
};