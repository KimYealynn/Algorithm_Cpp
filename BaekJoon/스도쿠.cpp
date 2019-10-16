#include <iostream>
#include <map>

using namespace std;

int board[9][9];
map<int, pair<int,int>> zero;

bool check_h(int a, int y){
    for(int j = 0; j < 9; j++){
        if(board[y][j] == a) return false;
    }
    return true;
}

bool check_v(int a, int x){
    for(int i = 0; i < 9; i++){
        if(board[i][x] == a) return false;
    }    
    return true;
}

bool check_r(int a, int y, int x){
    y = y / 3 * 3;
    x = x / 3 * 3;
   
    for(int i = y; i < y + 3; i++){
        for(int j = x; j < x + 3; j++){
            if(board[i][j] == a) return false;
        }
    }
    return true;
}

bool solve(int z){
    int y = zero[z].first;
    int x = zero[z].second;

    for(int i = 1; i < 10; i++){
        if(check_h(i, y) && check_v(i, x) && check_r(i, y, x)){
            board[y][x] = i;
            if(z == zero.size()-1) return true;
            if (solve(z + 1) ) return true;
            board[y][x] = 0;
        }
    }

    return false;
}


int main(){
    int cnt = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(board[i][j]==0)
                zero[cnt++] = make_pair(i,j);
        }
    }

    solve(0);
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout<<endl;
    }
    
    return 0;
}