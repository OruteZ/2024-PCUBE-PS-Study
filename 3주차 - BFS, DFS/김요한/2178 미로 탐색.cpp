#include<iostream>
#include<math.h>
#include<queue>
#include<algorithm>
using namespace std;



int N, M;
char map[101][101];
char visit[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int check[101][101];


void BFS(int x, int y) {
	visit[x][y] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M) {
				if (map[next_x][next_y] == '1' && visit[next_x][next_y] == 0) {
					check[next_x][next_y] = check[x][y] + 1;
					visit[next_x][next_y] = 1;
					q.push(make_pair(next_x, next_y));
				}
			}
		}
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	BFS(0, 0);
	cout << check[N - 1][M - 1] + 1;
}


