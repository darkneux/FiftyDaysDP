class Solution {
public:

    bool dfs(vector<vector<int>>&graph,int node,vector<int>&visited,bool f){
     if(visited[node]!=-1){
            if((visited[node] && !f) || (!visited[node] &&  f))return false;
            return true;
        }
        visited[node]=f;
        for(int i = 0;i < graph[node].size();++i){
            bool ch = dfs(graph,graph[node][i],visited,!f);
            if(!ch)return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();       
        vector<int>visited(n,-1);
        for(int i = 0;i  < n;++i){
            if(visited[i]==-1){
            if(!dfs(graph,i,visited,0))return false;
            }
        }
        return true;
        
    }
};

