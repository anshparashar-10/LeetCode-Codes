class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        int cntFrsh = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2; 
                    
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j]==1){
                    cntFrsh++;
                }
            }
        }

        int time = 0;
        int Frow[] = {-1,0,+1,0};
        int Fcol[] = {0,1,0,-1}; 
        int cnt = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time,t);
            q.pop();
            for(int i = 0;i<4;i++){
                int row = r+Frow[i];
                int col = c+Fcol[i];

                if(row>=0 && row<n && col>=0 && col<m && vis[row][col]!=2 && grid[row][col] == 1){
                    q.push({{row,col},t+1});
                    vis[row][col] = 2;
                    cnt ++;
                }
            }
        }
        if(cnt!=cntFrsh) return -1;
        
        return time;
    }
};
