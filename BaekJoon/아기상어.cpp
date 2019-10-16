#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int map[20][20];
int baby_x, baby_y;
int baby_size = 2, baby_ate = 0;
int fish_num;

int Y[4] = {-1, 0, 0, 1}; // 상0 좌1 우2 하3
int X[4] = {0, -1, 1, 0};

int find_fish(){
    bool visit[20][20] = {{false,},};
    int turn = 0;
    int find = 0;
    queue<vector<int>> Q;
    vector<vector<int>> fish;
    Q.push(vector<int> {baby_y, baby_x, -1, 1, find});
    
    while(!find){
        queue<vector<int>> new_Q;
        while(!Q.empty()){ // new_Q를 이용해서 find가 발생한 턴에서의 다른 push된 위치를 무시하게하는 것
            vector<int> shark = Q.front();
            Q.pop();
            for(int i = 0; i < 4; i++){
                if(shark[2] + i == 3) continue;                 // 되 돌아가기 방지
                int y = shark[0] + Y[i], x = shark[1] + X[i];               // 이동
                if(y < 0 || y >= N || x < 0 || x >= N) continue;       // 이탈 방지
                if(visit[y][x]) continue;
                visit[y][x] = true;

                if(map[y][x] != 0 && map[y][x] < baby_size){ //    작은 물고기 찾음
                    fish.push_back(vector<int> {y,x});
                    find = shark[3];
                }
                if(map[y][x] > baby_size) continue;  // 큰 물고기가 있으면 못지나감
                if(find) continue;
                new_Q.push(vector<int>{y, x, i, shark[3]+1});
            }
        }
        if(new_Q.empty()) break;
        Q = new_Q;
    }
    
    if(find){
        sort(fish.begin(), fish.end());
        map[fish[0][0]][fish[0][1]] = 0;
        baby_y = fish[0][0];
        baby_x = fish[0][1];
        fish_num--;
        return find;
    }
    return 0;
}

int solve(){
    int total_time = 0;
    while(true){
        int t = find_fish();
        total_time += t;
        
        if(t == 0) break;
        if(fish_num == 0) break;
        if(++baby_ate == baby_size){
            baby_size++;
            baby_ate = 0;
        }
    }
    return total_time;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                baby_y = i;
                baby_x = j;
                map[i][j] = 0;
            }
            else if(map[i][j] != 0) fish_num++;
        }
    }
    
    cout << solve() << endl;
    return 0;
}