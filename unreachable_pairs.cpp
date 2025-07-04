class Solution {
public:
vector<int>sizeo;
unordered_set<int>visited;
int  dfs(int src,unordered_set<int>&visited,vector<vector<int>>&graph,int &count){
 
    
    visited.insert(src);
  
    for(auto neighbour:graph[src]){
        if(visited.find(neighbour)==visited.end()){
          ;
            count++;
            dfs(neighbour,visited,graph,count);

        }
    }

   
    
    return count; ;
}
int connected_component(int n,vector<vector<int>>&graph,unordered_set<int>&visited){
    int ans = 0;
   
    for(int i =0; i<n; i++){
        
        if(visited.find(i)==visited.end()){
            int count = 1;
            ans++;
            dfs(i,visited,graph,count);
            sizeo.push_back(count);
                    }
    }
    return ans;
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(int i =0; i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int connected =connected_component(n,graph,visited);
        for(int i =0; i<sizeo.size();i++){
            cout<<sizeo[i]<<" ";
        }  
       long long total_pairs = (long long )n*(n-1)/2;
       long long total_reachable_pairs = 0;
       for(int i =0; i<sizeo.size();i++){
        total_reachable_pairs +=(long long)sizeo[i]*(sizeo[i]-1)/2;
       }
       return total_pairs-total_reachable_pairs;

    }
};
