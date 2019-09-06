using namespace std;

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <utility>

#define SIZE 102

typedef struct point{ int y, x; };

bool MAP[SIZE][SIZE], S[SIZE][SIZE];
vector<point> P_snake;
queue<pair<int,point>> MOVE;
int N, A;

point HEAD[] = {(point){0,1},(point){1,0},(point){0,-1},(point){-1,0}};
int i, j;

bool safe_boundary(point P){
	return (P.x < N) and (P.x >= 0) and (P.y < N) and (P.y >= 0);
}

bool safe_self(point P){
	if(P_snake[0].y == P.y and P_snake[0].x == P.x and MAP[P.y][P.x])
		return false;

	for(int s = 1; s < P_snake.size(); s++)
		if (P_snake[s].y == P.y and P_snake[s].x == P.x)
			return false;
	return true;
}

bool move_snake(point new_s, point HEAD){
	if(!safe_boundary(new_s) or !safe_self(new_s))
		return false;
	
	P_snake.insert(P_snake.begin(), new_s);
	S[new_s.y][new_s.x] = true;
	if(MAP[new_s.y][new_s.x])
		MAP[new_s.y][new_s.x] = false;
	else{
		S[P_snake.back().y][P_snake.back().x] = false;
		P_snake.pop_back();
	}
    
	return true;
}

int play(){
	point new_s;
	int cnt = 0;
	point head = HEAD[0];
	
	while(!MOVE.empty()){
		int sec = MOVE.front().first - cnt;
		
		while(sec--){
			cnt++;
			new_s = (point) {P_snake[0].y+head.y, P_snake[0].x+head.x};
			
			if(! move_snake(new_s, head))
				return cnt;
		}
		head = MOVE.front().second;
		MOVE.pop();
	}
	
	while(safe_boundary(new_s) and safe_self(new_s)){
		cnt++;
		new_s = (point) {P_snake[0].y+head.y, P_snake[0].x+head.x};
		
		if(! move_snake(new_s, head))
			return cnt;	
	}
    
	return cnt;
}

int main(){
	cin >> N >> A;
	for( i = 0; i < A; i++){
		int y, x;
		cin >> y >> x;
	    MAP[y-1][x-1] = true;
	}
	int M;
	cin >> M;
	int h=0;
	while(M--){
		int sec;
		char turn;
		point head;
		cin >> sec >> turn;
		if(turn=='L')
			h = (h==0) ? 3 : h-1;
		else
			h = (h+1) % 4;
		head = HEAD[h];
		MOVE.push(make_pair(sec,head));
	}
	S[0][0] = true;
	
	P_snake.push_back((point){0, 0});
	
	cout<<play();
		  
	return 0;
}
