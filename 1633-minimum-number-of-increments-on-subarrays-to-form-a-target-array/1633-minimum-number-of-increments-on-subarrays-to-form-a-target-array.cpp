class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        //can go by a recursive approach , or by actually decrementing values 
        //find min values , around them the increments are done 

        //optimal approach : a[i] > a[i-1] then difference no.of steps are needed 
        int res = target[0];

        for(int i=1;i<target.size() ; i++){
            if(target[i] > target[i-1]){
                res += (target[i] - target[i-1]);
            }
        }

        return res;
    }
};