#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<vector<int>> f00{ vector<int> {1,1},vector<int> {1,1}};
vector<vector<int>> f01{ vector<int> {1,1,1,1}};
vector<vector<int>> f02{ vector<int>{1,1,0}, vector<int>{0,1,1}};
vector<vector<int>> f03{ vector<int>{0,1,1}, vector<int>{1,1,0}};
vector<vector<int>> f04{ vector<int>{0,1,0}, vector<int>{1,1,1}};
vector<vector<int>> f05{ vector<int>{1,0,0}, vector<int>{1,1,1}};
vector<vector<int>> f06{ vector<int>{0,0,1}, vector<int>{1,1,1}};

vector<vector<int>> figures[20] = {f00,f01,f02,f03,f04,f05,f06, };

int N, M, idx = 7;
int map[501][501];

vector<vector<int>> turn(vector<vector<int>> figure){
    int n = figure.size(), m = figure[0].size(); 
    vector<vector<int>> new_figure(m, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            new_figure[abs(m-j-1)][i] = figure[i][j];
        }
    }
    return new_figure;
}

int find_max(int f){
    int max = 0;
    vector<vector<int>> figure = figures[f];
    int n = figure.size(), m =figure[0].size();
    
    for(int i = 0; i < N-n+2; i++){
        for(int j = 0; j < M-m+3; j++){
            int num = 0;
            for(int y = 0; y < n; y++){
                for(int x = 0; x < m; x++){
                    num +=figure[y][x]*map[i+y][j+x];
                }
            }
            max = max < num ? num : max;
        }
    }
    return max;
}

int solve(){
    int max = 0;
    
    for(int i = 0; i < 19; i++){
        int num = find_max(i);
        max = max < num ? num : max;
    }
    return max;
}


int main(){
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    
    for(int i = 1; i < 7; i++){
        int e = i < 4? 1: 3;
        vector<vector<int>> figure = figures[i], new_figure;
        for(int j = 0; j < e; j++){
            new_figure = turn(figure);
            figures[idx++] = new_figure;
            figure = new_figure;
        }
    }
    
    cout << solve() << endl;
    return 0;
}