class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int num_circle = 0;
        
        for(int i=0; i<M.size();i++){
            for(int j=i; j<M.size();j++){
                if(M[i][j]==1) {
                    M[i][j] = num_circle+2;
                    check_friends(M, j, ++num_circle);}
            }
        }
        return num_circle;
    }
private:
    void check_friends(vector<vector<int>>& M, int j, int num_circle){
        for(int x=0; x < M.size(); x++){
            if(M[j][x]==1) {
                M[j][x] = num_circle+1;
                M[x][x] = num_circle+1;
                check_friends(M, x, num_circle);}
        }
    }
};