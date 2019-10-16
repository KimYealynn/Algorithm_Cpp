#include <iostream>

using namespace std;

int N, M, H;

bool i2i(int map[][11]){
    for(int i = 0; i < N; i++){
        int x = i, y = 0;
        while(y < H){
            while(map[y][x] == 0) y++;
            if(map[y][x] == -1){x--; y++;}
            if(map[y][x] == 1){x++; y++;}
        }
        if(x != i) return false;
    }
    return true;
}

bool can_make(int map[][11], int a){
    int y = a/(N-1), x = a%(N-1); 
    return map[y][x] == 0 && map[y][x+1] == 0;
}

void set(int map[][11], int a, int s){
    int y = a/(N-1), x = a%(N-1);
    map[y][x] = s;
    map[y][x+1] = s*-1;
}

int solve(int map[][11]){
    int min = 4;
    for(int a = 0; a < (N-1)*H; a++){
        while(!can_make(map,a)) a++;
        set(map, a, 1);
        if(i2i(map)) min = 1;
        for(int b = a+1; b < (N-1)*H; b++){
            while(!can_make(map, b)) b++;
            set(map, b, 1);
            if(i2i(map)) min = min > 2 ? 2 : min;
            for(int c = b+1; c < (N-1)*H; c++){
                while(!can_make(map, c)) c++;
                set(map, c, 1);
                if(i2i(map)) min = min > 3 ? 3 : min;
                set(map, c, 0);
            }
            set(map, b, 0);
        }
        set(map, a, 0);
    }
    if(min == 4) return -1;
    return min;
}

int main()
{
    int result = 0;
    int map[31][11] = {{0,},};
    cin >> N >> M >> H;
    
    while(M--){
        int a, b; cin >> a >> b;
        map[a-1][b-1] = 1;
        map[a-1][b] = -1;
    }
    
    if(!i2i(map)) result = solve(map);
    cout << result << endl;
    
    return 0;
}