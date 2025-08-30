class Solution {
public:
    vector<vector<int>>ans;
    int n,k;
    void f(int num, int sum , vector<int>vec)
    {
        if(sum==n && vec.size()==k){
            ans.push_back(vec);return;
        }
        if(sum>n || vec.size()>k)return;//invalid cases
        
        for(int i=num;i<10;i++)
        {
            vec.push_back(i);
            f(i+1 , sum+i , vec);//this acts as pick
            vec.pop_back(); //this is not pick
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        this->n = n;
        this->k = k;
        vector<int>vec;
        f(1,0,vec);
        return ans;
    }
};