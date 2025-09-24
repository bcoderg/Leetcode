class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int oneBuy=INT_MAX, twoBuy = INT_MAX, oneSell=0,  twoSell=0;
        for(auto p: prices){
            oneBuy = min(oneBuy , p);
            oneSell = max(oneSell , p - oneBuy);//oneSell = cur - oneBuy 
            twoBuy = min(twoBuy , p - oneSell);
            //if we already have 100 profit stored in oneSell, then twoBuy item(300) cost = 300 - 100 = 200 only 

            twoSell = max(twoSell , p - twoBuy);
        }
        return twoSell;
    }
};