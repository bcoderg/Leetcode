class Solution {
public:
    int candy(vector<int>& v) {
        //another efficient approach by using peak , down calculations
        int sum=1;//0th idx only 1 candy 
        int i=1  , n = v.size();
        while(i<n){
            //no peak
            while(i<n && v[i]==v[i-1]){
                i++;
                sum++;
            }

            int peak=1;
            while(i<n && v[i]>v[i-1]){//peak increase
                i++;
                peak++;
                sum+=peak;
            }

            int down=0;
            while(i<n && v[i]<v[i-1]){//down decrease
                i++;
                down++;
                sum+=down;
            }
            down++;
            if(down > peak){
                sum+=(down-peak);
            }
        }
        return sum;
    }
};