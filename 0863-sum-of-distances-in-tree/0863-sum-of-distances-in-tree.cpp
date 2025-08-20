class Solution {
public:
    vector<int>subtree , distance;
    vector<vector<int>>adj;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
	adj.assign(n , vector<int>());
	for(auto &x:edges){
	 adj[x[0]].push_back(x[1]);
	 adj[x[1]].push_back(x[0]);
	}
	
	subtree.assign(n , 1);
	distance.assign(n , 0);
	
	dfs(0,-1);//calculates distance for root , subTree size for all nodes
	
	//distances of child node is related to parent node 
	//nodes in child substree - 1 step closer , other subtree 1 step farther 
	dfs2(0,-1);//updates distances of all nodes
	
	return distance;
    }
    
    void dfs(int root , int par){
	for(auto x:adj[root]){
	   if(x==par)continue; 
	   dfs(x , root);
	   subtree[root] += subtree[x];
	   distance[root] += (distance[x] + subtree[x]);
	}
    }
	
    void dfs2(int root , int par){
	for(auto x:adj[root]){
	   if(x==par)continue; 
	   distance[x] = (distance[root] - subtree[x] + subtree.size() - subtree[x]);//this subtree -1 , n-this subtree +1
	   dfs2(x , root);
	}
    }
};