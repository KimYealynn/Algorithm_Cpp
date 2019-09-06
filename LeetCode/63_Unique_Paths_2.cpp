class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m = Grid.size();
        int n = Grid[0].size();
        int mat[m][n] = {0,};
        bool check = false;
        
        for(int i =0; i< m ; i++){
            if(Grid[i][0]) check = true;
            if(check) mat[i][0] = 0;
            else mat[i][0] = 1;
        }
        check = false;
        for(int i =0; i< n ; i++){
            if(Grid[0][i]) check = true; 
            if(check) mat[0][i] = 0;
            else mat[0][i] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(!Grid[i][j]) mat[i][j] = mat[i-1][j]+mat[i][j-1];
            }
        }
        
    
        return mat[m-1][n-1];
    }
};

