class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ways(m+2, vector<int>(n+2, 0));
        
        ways[1][1] = 1;
        for (int i=1; i<=m;++i)
            for (int j=1; j<=n;++j)
                ways[i][j] += ways[i-1][j] + ways[i][j-1];
        
        return ways[m][n];
    }
};
