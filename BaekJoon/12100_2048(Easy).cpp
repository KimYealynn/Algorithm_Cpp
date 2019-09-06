using namespace std;

#include <iostream>
#include <cstring>//memcpy
#include <algorithm>

#define SIZE 20
#define MAX(a, b) a>b?a:b

int MAP[SIZE][SIZE];
int N = 0;
int max_val = 0;
int i, j;
bool moved = false;

void slide_UP(){
	for(j = 0; j < N; j++){
		int cnt = 0;
		for(i = 0; i < N; i++){
			if(MAP[i][j]!=0){
				if(cnt != i) moved = true;
				MAP[cnt++][j] = MAP[i][j];
			}
		}
		while(cnt<N) MAP[cnt++][j] = 0;
	}
}

void slide_LEFT(){
	for(i = 0; i < N; i++){
		int cnt = 0;
		for(j = 0; j < N; j++){
			if(MAP[i][j]!=0){
				if(cnt != j) moved = true;
				MAP[i][cnt++] = MAP[i][j];
			}
		}
		while(cnt<N) MAP[i][cnt++] = 0;
	}
}

void flip_UD(){
	for(j = 0; j < N; j++){
		for(i = 0; i <= (N-1)/2; i++){
			int temp = MAP[i][j];
			MAP[i][j] = MAP[N-1-i][j];
			MAP[N-1-i][j] = temp;
		}
	}
}

void flip_LR(){
	for(i = 0; i < N; i++){
		for(j = 0; j <= (N-1)/2; j++){
			int temp = MAP[i][j];
			MAP[i][j] = MAP[i][N-1-j];
			MAP[i][N-1-j] = temp;
		}
	}
}

//MAP[y][x]
bool move(int AR){
	moved = false;
	if(AR < 2){ //up down
		if(AR==1) flip_UD();// down
		slide_UP();
		for(j = 0; j < N; j++){
			for(i = 0; i < N-1; i++){
				if(MAP[i][j] != 0 and MAP[i][j] == MAP[i+1][j]){
					moved = true;
					MAP[i][j] *= 2;
					for(int k = i+1; k < N-1; k++)
						MAP[k][j] = MAP[k+1][j];
					MAP[N-1][j] = 0;
				}
			}
		}
		if(AR==1) flip_UD();
	}	
	else{		//left right
		if(AR==3) flip_LR();// right
		slide_LEFT();
		for(i = 0; i < N; i++){
			for(j = 0; j < N-1; j++){
				if(MAP[i][j] != 0 and MAP[i][j] == MAP[i][j+1]){
					moved = true;
					MAP[i][j] *= 2;
					for(int k = j+1; k < N-1; k++)
						MAP[i][k] = MAP[i][k+1];
					MAP[i][N-1] = 0;
				}
			}
		}
		if(AR==3) flip_LR();
	}
	return moved;
}

int solve(int cnt){
	int ans[4] = {-1, -1, -1, -1};
	if(cnt < 5){
		int o_MAP[SIZE][SIZE];
		memcpy(o_MAP, MAP, sizeof(MAP));
		
		for(int k = 0; k < 4; k++){
			if (move(k)) solve(cnt+1);
			memcpy(MAP, o_MAP, sizeof(MAP));
		}
		if(ans[0]+ans[1]+ans[2]+ans[3] != -4){
			sort(ans,ans+4);
			return ans[3];
		}
	}
	for(i = 0; i < N; i++) 
		for(j =0; j < N; j++)
			max_val = MAX(max_val, MAP[i][j]);
	return max_val;
}

int main(){
	cin >> N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> MAP[i][j];
		}
	}
	
	cout<<solve(0)<<endl;
	return 0;
}
