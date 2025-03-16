class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long res=LLONG_MAX;
        int mx=*max_element(ranks.begin(),ranks.end());
        long long maxTime=(long long)cars*cars*mx;
        long long l=0,r=maxTime;

        auto isValid = [&](long time)->bool{
            int count=0;
            for(auto r:ranks){
                int r_c=sqrt(time/r);
                if(count>=cars)return true;
                count+=r_c;
            }
            return count>=cars;
        };

        while(l<=r){
            long long m=l+(r-l)/2;
            if(isValid(m)){
                res=min(res,m);
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return res;
    }
};