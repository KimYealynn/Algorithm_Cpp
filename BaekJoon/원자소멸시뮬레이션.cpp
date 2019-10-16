SWEA  5648 원자소멸 시뮬레이션
#include<iostream>
#include <vector>
#include <utility>

using namespace std;
pair<int, int> MAP[4008][4008];
int turn = 0;

typedef struct element{
    int x, y, d, m;
    bool live = true;
    
    void move(){
        if(d == 0) y++;
        else if(d ==1) y--;
        else if(d ==2) x--;
        else if(d ==3) x++;
        
        if( y> 4000 || y < 0 || x > 4000 || x < 0) 
            live = false;
    }
    
}element;

int main(int argc, char** argv)
{
    int test_case;
    int T, N;
    
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int result = 0;

        vector<element> dots;
        cin >> N;
        int cnt_dots = N;
        
        while(N--){
            element e;
            cin >>e.x >> e.y >> e.d >> e.m ;
            e.x *=2;
            e.y *=2;
            e.x += 2000;
            e.y += 2000;

            dots.push_back(e);
        }
        int prev_turn = turn;
        while(turn++ < prev_turn + 4008){
            for(int i = 0; i <dots.size(); i++){
                dots[i].move();
                if(!dots[i].live) continue;
                
                if(MAP[dots[i].y][dots[i].x].first == turn){
                    MAP[dots[i].y][dots[i].x].first *= -1;
                    dots[MAP[dots[i].y][dots[i].x].second].live = false;
                    dots[i].live = false;
                    result += dots[MAP[dots[i].y][dots[i].x].second].m;
                    result += dots[i].m;
                    cnt_dots -=2;
                    continue;
                }
                if(MAP[dots[i].y][dots[i].x].first ==( -1 * turn)){
                    dots[i].live = false;
                    result += dots[i].m;
                    cnt_dots--;
                    continue;
                }
                if(cnt_dots == 1) break;
                MAP[dots[i].y][dots[i].x].first = turn;
                MAP[dots[i].y][dots[i].x].second = i;
            }
            if(cnt_dots == 1) break;
        }

        cout<<"#"<<test_case<<" "<<result<<endl;
    }
    return 0;
}