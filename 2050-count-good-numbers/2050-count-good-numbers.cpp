class Solution {
public:
    int m=1e9+7;

    int findPower(long long a , long long b){
        if(b==0){
            return 1;
        }
        long long half=findPower(a,b/2);
        long long res=(half*half)%m;
        if(b&1){
           res = (res*a)%m;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        int even=5 , prime=4;
        long long even_i=(n+1)/2;
        long long odd_i=n/2;
        return (long long)findPower(even , even_i) * findPower(prime,odd_i)%m;
    }
};