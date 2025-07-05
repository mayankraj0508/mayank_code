class Solution {
public:
    bool dfs(int src,vector<int>&color,int col,vector<vector<int>>&graph){
        color[src] = col;
        for(auto neighbour:graph[src]){
            if(color[neighbour]==-1){
              bool res  = dfs(neighbour,color,!col,graph);
              if(res==false){
                return false;
              }
            }
            else{
                if(color[neighbour]==col){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n =  graph.size();
        vector<int>color(n,-1);
    
        for(int i =0;i<n; i++){
            if(color[i]==-1){
            bool res = dfs(i,color,0,graph);
            if(res==false){
                return false;
            }
            }
        }
        
        
        return true;
    }
};
