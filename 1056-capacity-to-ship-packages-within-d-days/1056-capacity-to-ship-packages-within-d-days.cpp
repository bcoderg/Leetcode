class Solution {
public:
//BS on ans
bool canShip(vector<int>&v , int minCapacity , int days)
{
    int cur = 0 , minDays = 1;
    for (int i = 0; i < v.size(); i++) {
        if (cur + v[i] <= minCapacity) {
            cur += v[i];
        }
        else {
            if(v[i] > minCapacity)return false;
            cur = v[i];
            minDays++;
        }
    }
    return minDays <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int l = *max_element(begin(weights) , end(weights)) , r = accumulate(begin(weights) , end(weights) , 0);
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (canShip(weights, m , days) ) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return l;
}
};