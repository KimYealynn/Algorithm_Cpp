#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, M;
char MAP[11][11];
int b_x, b_y, r_x, r_y;
int h_x, h_y;
int X[] = {0, -1, 1, 0}; // 0상 1좌 2우 3상
int Y[] = {-1, 0, 0, 1};
bool visit[11][11][11][11] = {{{{false,},},},};


bool can_go(int d, int y, int x){
    int i = y + Y[d];
    int j = x + X[d];
    
    if(MAP[i][j] == '#') return false;
    if(i == r_y && j == r_x) return false;
    if(i == b_y && j == b_x) return false;
    return true;
}

bool is_R_before_B(int d){
    if(d == 0 && r_y < b_y) return true;    
    else if(d == 3 && r_y > b_y) return true;
    else if(d == 1 && r_x < b_x) return true;
    else if(d == 2 && r_x > b_x) return true;
    return false;
}

bool move_R(int d){
    while(MAP[r_y][r_x] != '#'){
        r_y += Y[d]; r_x += X[d];
        if(r_y == b_y && r_x == b_x) break;
        if(MAP[r_y][r_x] == 'O'){
            r_y = -1; r_x = -1;
            return true;
        }
    }
    r_y -= Y[d];
    r_x -= X[d];
    return false;
}

bool move_B(int d){
    while(MAP[b_y][b_x] != '#'){
        b_y += Y[d]; b_x += X[d];
        if(r_y == b_y && r_x == b_x) break;
        if(MAP[b_y][b_x] == 'O'){
            b_y = -1; b_x = -1;
            return true;
        }
    }
    b_y -= Y[d];
    b_x -= X[d];
    return false;
}


int play_game(){
    queue<vector<int>> Q;
    Q.push(vector<int> {r_y, r_x, b_y, b_x, -10, 0});
    
    while(!Q.empty()){
        vector<int> R = Q.front();
        Q.pop();
        
        int dir = R[4], turn = R[5] + 1;
        visit[r_y][r_x][b_y][b_x] = true;
        if(turn > 10) return -1;
        
        for(int d = 0; d < 4; d++){
            bool goal_R, goal_B;
            r_y = R[0]; r_x = R[1];
            b_y = R[2]; b_x = R[3];
            
            if(d + dir == 3) continue;
            if(!can_go(d, r_y, r_x) && !can_go(d, b_y, b_x)) continue;
            if(visit[r_y+Y[d]][r_x+X[d]][b_y+Y[d]][b_x+X[d]]) continue;
            if(is_R_before_B(d)){
                goal_R = move_R(d);
                goal_B = move_B(d);
            }
            else{
                goal_B = move_B(d);
                goal_R = move_R(d);
            }
            if(goal_B) continue;
            if(goal_R == 1) return turn;
            
            Q.push(vector<int> {r_y, r_x, b_y, b_x, d, turn});
        }
    }
    return -1;
}


int main()
{
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 'B'){
                b_x = j; b_y = i;
                MAP[i][j] = '.';
            }
            else if(MAP[i][j] == 'R'){
                r_x = j; r_y = i;
                MAP[i][j] = '.';
            }
            else if(MAP[i][j] == 'O'){
                h_x = j; h_y = i;
            }
        }
    }
    
    cout << play_game() << endl;
    
    return 0;
}