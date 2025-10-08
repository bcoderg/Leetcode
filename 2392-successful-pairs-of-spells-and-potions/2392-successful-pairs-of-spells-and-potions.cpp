class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size() , m = potions.size();
        sort(begin(potions) , end(potions));

        auto getPairCount = [&](int spell)->int{
            int l = 0 , r = m - 1;
            while(l<=r){
                int m = l + (r - l)/2;
                if( 1LL* spell * potions[m] < success){//if less move forward
                    l = m + 1;
                }
                else{
                    r = m - 1;
                }
            }
            return m - l;
        };

        vector<int>pairs;
        for(int& spell: spells){
            int count = getPairCount(spell);
            pairs.push_back(count);
        }

        return pairs;
    }
};