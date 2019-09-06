#include <iostream>
#define CLEAN 2
#define NONE 0
#define WALL 1

using namespace std;

int main() {
	int X, Y, x, y, d;
	int mat[51][51];
	int dic[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
	int cnt = 0;

	cin >> Y >> X;
	cin >> y >> x >> d;

	for (int i = 0; i < Y; i++)
		for (int j = 0; j < X; j++)
			cin >> mat[i][j];

	while (true) {
		int forward = d;
		d = (d == 0) ? 3 : d - 1;
		if (mat[y][x] != CLEAN) {
			cnt++;
			mat[y][x] = CLEAN;
		}
		while (true) {
			if (mat[y + dic[d][0]][x + dic[d][1]] == NONE) {
				y += dic[d][0];
				x += dic[d][1];
				break;
			}
			if (forward == d) {
				if (mat[y - dic[forward][0]][x - dic[forward][1]] == WALL) {
			        cout<<cnt;
                    return 0;
				}
				else {
					d = forward;
					y -= dic[forward][0];
					x -= dic[forward][1];
					break;
				}
			}
			d = (d == 0) ? 3 : d - 1;
		}
	}
	return 0;
}
