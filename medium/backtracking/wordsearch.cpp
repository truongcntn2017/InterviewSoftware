class Solution {
private:
    int nextX[4] = {1, -1, 0, 0};
    int nextY[4] = {0, 0, 1, -1};
    vector<vector<bool>> visited;
public:
    bool isInGrid(vector<vector<char>>& board, int u, int v){
        return (0<= u && u<board.size()) && (0<=v && v<board[0].size());
    }
    void dfs(vector<vector<char>>& board, string word, bool& isExist, int u, int v, int index){
        
        if (!isExist && isInGrid(board, u, v)){
            if (!visited[u][v] && word[index] == board[u][v]){
                visited[u][v] = true;
                
                if (index == word.size()-1){
                    isExist = true;
                    return;
                }
                else{
                    for (int k = 0; k<4; ++k)
                        dfs(board, word, isExist, u+nextX[k], v+nextY[k], index+1);
                }
                
                visited[u][v] = false;
            }
        }
    }
    void existHelper(vector<vector<char>>& board, string word, bool& isExist){
        if (!board.empty()){
            visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
            
            for (int u=0; u<board.size();++u){
                for (int v=0; v<board[0].size(); ++v){
                    dfs(board, word, isExist, u, v, 0);
                }
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool isExist = false;
        existHelper(board, word, isExist);
        return isExist;
    }
};
