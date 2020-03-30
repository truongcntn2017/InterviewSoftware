
class Solution {
public:
    int nextX[4] = {1, -1, 0, 0};
    int nextY[4] = {0,  0, 1, -1};
    
    bool isInGrid(vector<vector<char>>& grid, int u, int v){
        return (0<=u && u<grid.size()) && (0<= v && v<grid[0].size());
    }
    bool isLand(vector<vector<char>>& grid, int u, int v){
        return (grid[u][v] == '1');
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int u, int v){
        if (isInGrid(grid, u, v)){
            if (!visited[u][v] && isLand(grid, u, v)){
                visited[u][v] = true;
                for (int k = 0; k<4;++k){
                    dfs(grid, visited, u + nextX[k], v + nextY[k]);     
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int nComponents = 0;
        
        if (grid.size()){
            vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
            for (int u=0; u<grid.size();++u)
                for (int v=0; v<grid[0].size();++v){
                    if (!visited[u][v] && isLand(grid, u, v)){
                        dfs(grid, visited, u, v);
                        nComponents++;
                    }
                }
        }
        
        return nComponents;
    }
};

