class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp; 
        int minEle =basket1[0];
        for(auto &x: basket1){
            minEle=min(minEle , x);
            mp[x]++;
        }
        for(auto &x: basket2){
            minEle=min(minEle , x);
            mp[x]--;
        }
        vector<int>swapNums;
        for(auto [cost,count]: mp){
            if(count==0)continue;
            if(count%2 != 0 )return -1; 

            int swaps = abs(count/2);
            for(int i=0;i<swaps;i++){
                swapNums.push_back(cost);
            }
        }
        //can use sort , but we only need first half for min cost swaps
        //so we can use nth element
        //nth element makes sure all values to it's left are less , right are greater than that one 
        //sort(begin(swapNums) , end(swapNums) );
        nth_element(begin(swapNums) , begin(swapNums)+swapNums.size()/2 , end(swapNums) );

        long long cost = 0;
        for(int i=0;i<swapNums.size()/2 ; i++){
            cost += min(swapNums[i] , 2*minEle);
        }
        return cost;
    }
};