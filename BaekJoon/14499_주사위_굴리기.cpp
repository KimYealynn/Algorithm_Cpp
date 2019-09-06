using namespace std;

#include <iostream>
#include <algorithm>
#define SIZE 20

int MAP[SIZE][SIZE];
int DICE[6] = {0};
int d_NUM = 0;

int N, M;
int X, Y;
int n, i, j;

bool check(int r){
	int x = X, y = Y;
	if(r==1)x++;
	else if(r==2)x--;
	else if(r==3)y--;
	else if(r==4)y++;
	
	if(x<0 or x>=M or y<0 or y>=N)
		return false;
	X = x;
	Y = y;
	return true;
}

void rolling(int r){
	int temp[6];
	copy(DICE, DICE + 6, temp);

	switch(r)
	{
		case 1:
			DICE[0]	= temp[3];
			DICE[1] = temp[1];
			DICE[2] = temp[0];
			DICE[3] = temp[5];
			DICE[4] = temp[4];
			DICE[5] = temp[2]; 
			break;
		case 2:
			DICE[0] = temp[2];
			DICE[1] = temp[1];
			DICE[2] = temp[5];
			DICE[3] = temp[0];
			DICE[4] = temp[4];
			DICE[5] = temp[3];
			break;
		case 3:
			DICE[0] = temp[4];
			DICE[1] = temp[0];
			DICE[2] = temp[2];
			DICE[3] = temp[3];
			DICE[4] = temp[5];
			DICE[5] = temp[1];
			break;
		case 4:
			DICE[0] = temp[1];
			DICE[1] = temp[5];
			DICE[2] = temp[2];
			DICE[3] = temp[3];
			DICE[4] = temp[0];
			DICE[5] = temp[4];
			break;
	}
}



int main(){	
	cin >> N >> M >> Y >> X >> n;
	for(i = 0; i<N; i++)
		for(j=0; j<M; j++)
			cin >> MAP[i][j];
	
	for(i = 0; i < n; i++){
		int dir;
		cin >> dir;
		if(check(dir)){
			rolling(dir);
			if( MAP[Y][X] == 0 ){
				MAP[Y][X] = DICE[5];
			}
			else{
				DICE[5] = MAP[Y][X];
				MAP[Y][X] = 0;
			}
			cout<< DICE[0]<< " ";
		}
	}
	return 0;
}