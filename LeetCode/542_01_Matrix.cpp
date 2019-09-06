class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int Y = matrix.size();
        int X = matrix[0].size();
        vector<vector<int> > result(Y, vector<int>(X, INT_MAX - 100000));
        
        if (Y==0) return matrix;
        
        for(int i = 0; i < Y; i++){
            for(int j = 0; j < X; j++){
                
                if( matrix[i][j] == 0) result[i][j] = 0;
                else{
                    if(i != 0) result[i][j] =  min(result[i][j], result[i-1][j] + 1); 
                    if(j != 0) result[i][j] =  min(result[i][j], result[i][j-1] + 1);   
                }                    
            }
        }
       
        for(int i = Y - 1 ; i >= 0; i--){
            for(int j = X - 1; j >= 0; j--){
                if( matrix[i][j] == 0) result[i][j] = 0;
                else{
                    if(i != Y-1) result[i][j] = min(result[i][j], result[i+1][j] + 1);   
                    if(j != X-1) result[i][j] = min(result[i][j], result[i][j+1] + 1); 
                }
            }
        }
    
        return result;
    }


};