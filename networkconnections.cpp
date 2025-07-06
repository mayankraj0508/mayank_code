class Solution {
public: 
    void dfs(int i,unordered_set<int>&visited,vector<vector<int>>&graph){
        visited.insert(i);
        if(i>=graph.size()){
            return ;
        }
      //  depth++;
        for(auto neighbour:graph[i]){
            if(visited.find(neighbour)==visited.end()){
             //  depth++;
             dfs(neighbour,visited,graph);
            }
        }
        return ;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int p = connections.size();
        unordered_set<int>vis;
        vector<vector<int>>graph(n);
        int ans = INT_MIN;
        for(int i = 0; i<connections.size();i++){
           graph[connections[i][0]].push_back(connections[i][1]);
           graph[connections[i][1]].push_back(connections[i][0]);
           
        }
   //    int depth = 1;
        unordered_set<int>visited;
        int connected = 0;
        for(int i=0; i<n; i++){
           
            if(visited.find(i)==visited.end()){
                connected++;
                 
                
                dfs(i,visited,graph);
            }

        }
      //  cout<<connected;
        int required_edges = connected-1;
        int l = n-1;
        if(connections.size()>=n-1){
            return required_edges;
        }
        else{
            return -1;
        }
        
           
  
    }
};
