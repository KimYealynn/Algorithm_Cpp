#include <iostream>
#include <vector>


using namespace std;

int main(){
    vector<int> files;
    int sum[501] = {0,};

    int T, N, a;
    cin >> T;
    while(T--){
        int dp[501][501] = {{0,}, };

        cin >> N;
        files.clear();
    
        for(int i = 1; i <= N; i ++) {
            cin >> a;
            files.push_back(a);
            sum[i] = sum[i-1] + a;
        }
        
        for(int x = 0; x < N; x++){
            int i =  0, j = x;
            for( ; j < N; j++, i++){
                if(i == j) continue;
                if(i + 1 == j) dp[i][j] = files[i] + files[j];
                else {
                    int min = 2123456789;
                    for(int k = i; k < j; k++){
                        int sum = dp[i][k]+dp[k+1][j];
                        min = min > sum ? sum : min;
                    }
                    dp[i][j] = min + sum[j+1] - sum[i];
                }
            }
        }
        cout << dp[0][N-1]<<endl;
    }
    return 0;