class Solution {
public:
    bool dfs(vector<int>&arr , int start , int n, vector<bool>&vis){

        if(start<0 || start>=n || vis[start]==true)return false;

        if(arr[start]==0)return true; 

        vis[start]=true; 

        int leftIdx=start - arr[start];
        int rightIdx=start + arr[start];
        return dfs(arr,leftIdx,n,vis) || dfs(arr,rightIdx,n,vis);;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>vis(n,0);
        //DFS 
        return dfs(arr,start+arr[start],n,vis) || dfs(arr,start-arr[start],n,vis);
    }
};