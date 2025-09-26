class Solution {
public:
    vector<int> findClosestElements(vector<int>& v, int k, int x) {
        
        int n=v.size();
        int l=0,r=n-k;
        while(l < r)
        {
            int m = (l + r) / 2;
            if(x - v[m] > v[m+k]-x )
                l = m + 1;
            else 
                r = m;
        }
        return vector<int>(begin(v)+l , begin(v)+l+k);
    }
};