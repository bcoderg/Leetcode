class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int ans=0;
        vector<int>v(n,1);
        //first all 1 

        //left to right increase
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                v[i]=v[i-1]+1;
            }
        }

        //right to left increase
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                v[i] = max(v[i] , v[i+1]+1 ); 
            }
        }
        ans=accumulate(v.begin() , v.end(),0);
        return ans;
    }
};