class Solution {
public:
    char kthCharacter(int k) {
        // we reach to a char only after , doubling from it's /2 position
        //then increasing the char value by 1 
        //total increases = total no.of times doubled
        //=total no.of set bits in binary of k-1 
        return 'a' + __builtin_popcount(k-1);
    }
};