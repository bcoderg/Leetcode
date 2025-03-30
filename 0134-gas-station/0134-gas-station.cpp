class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g=0 , idx=0 , n=gas.size();
        if(accumulate(cost.begin(),cost.end(),0) > accumulate(gas.begin(),gas.end(),0))return -1;

        for(int i=0;i<n;i++)
        {
            g+=(gas[i]-cost[i]);
            if(g<0)
            {
                idx=i+1;
                g=0;
            }
        }
        return idx;
    }
};



// 1 2 3 4 5 (gas)
// 3 4 5 1 2 (cost)


