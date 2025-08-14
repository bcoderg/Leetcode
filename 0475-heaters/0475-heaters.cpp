class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = heaters.size();
        sort(begin(heaters) , end(heaters));
        int mx=0;

        auto getMaxRad = [&](int house)->int{
            int l=0 , r=n-1;
            int leftNear=INT_MAX , rightNear=INT_MAX;
            while(l<=r){
                int m = l+(r-l)/2;
                if(heaters[m] == house){
                    return 0;
                }
                else if(heaters[m]>house){
                    // cout<<"rightNear = "<<rightNear<<"\n";
                    rightNear = heaters[m] - house;
                    r = m-1;
                }
                else{
                    leftNear = house - heaters[m];
                    // cout<<"leftNear = "<<leftNear<<"\n";
                    l = m+1;
                }
            }
            // cout<<"l,r near = "<<leftNear<<" "<<rightNear<<"\n";
            return min(leftNear , rightNear);
        };

        for(int h: houses){
            int maxRad = getMaxRad(h);
            mx = max(mx , maxRad);
        }
        return mx;
    }
};