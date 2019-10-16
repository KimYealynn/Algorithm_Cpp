#include <iostream>

using namespace std;

int MAP[101][101] = {{0,},};
int N;

void search(int i, int j, int k, bool visit[][101]){
    if(i < 0 || i >= N || j < 0 || j >= N) return;
    if(MAP[i][j] <= k || visit[i][j]) return;
    visit[i][j] = true;
    search(i-1, j, k, visit);
    search(i, j-1, k, visit);
    search(i+1, j, k, visit);
    search(i, j+1, k, visit);
}

int main(){
    int max_area = 0;
    int max_len = 0;
    int min_len = 101;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
            max_len = max_len < MAP[i][j]? MAP[i][j]: max_len;
            min_len = min_len > MAP[i][j]? MAP[i][j]: min_len;
        }
    }
    
    for( int k = min_len - 1; k < max_len; k ++){
        bool visit[101][101] = {{false,},};
        int cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(MAP[i][j] > k && !visit[i][j]){
                    search(i, j, k, visit);
                    cnt++;
                }
            }
        }
        max_area = max_area < cnt ? cnt : max_area;
    } 
    
    cout<< max_area<<endl;
    
    return 0;
} 