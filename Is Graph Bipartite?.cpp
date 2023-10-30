class Solution {
private :
    bool f(int start,vector<int>& vis,vector<vector<int>>& graph){
        
        queue<int> q;
        q.push(start);
        vis[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : graph[node]){
                if(vis[it]==-1){
                    vis[it] = !vis[node];
                    q.push(it);
                }
                else if(vis[it]==vis[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i = 0;i<graph.size();i++){
            if(vis[i]==-1){
                if(f(i,vis,graph)==false) return false;
            }
        }
        return true;
    }
};
