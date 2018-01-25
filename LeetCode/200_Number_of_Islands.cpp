class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        for(int i =0; i<grid.size(); i++){
            for(int j =0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    num_island++;
                    check_arround(grid, i, j);
                }
            }
        }
        return num_island;
    }
    
private:
    int num_island = 0, state_j;
    
    void check_arround(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] == '1') grid[i][j] = '1' + num_island;
        else return;

        if(i>0) check_arround(grid, i-1, j);
        if(i<grid.size()-1) check_arround(grid, i+1,j);
        if(j>0) check_arround(grid, i, j-1);
        if(j<grid[0].size()-1) check_arround(grid, i, j+1);
    }
}; 