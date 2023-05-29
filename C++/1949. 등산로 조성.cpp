#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct node {
	int y;
	int x;
	int value;
	bool visited;
};

node **map;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int N, result;

void run(node now, int lv, int k) {
	result = max(result, lv);
	for (int i = 0; i < 4; i++) {
		int ny = now.y + dy[i];
		int nx = now.x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (map[ny][nx].visited) continue;
		
		int diff = map[ny][nx].value - now.value;
		if (diff >= k) continue;

		map[ny][nx].visited = true;
		if(map[ny][nx].value < now.value) run(map[ny][nx], lv + 1, k);
		else {
			map[ny][nx].value = map[ny][nx].value - diff - 1;
			run(map[ny][nx], lv + 1, 0);
			map[ny][nx].value = map[ny][nx].value + diff + 1;
		}
		map[ny][nx].visited = false;
	}
}


int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test_case;
	int T;

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int tVal, K;
		int targetVal = 0;
		
		result = 0;

		cin >> N >> K;

		map = new node*[N];
		for (int i = 0; i < N; i++) map[i] = new node[N] {};

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> tVal;
				map[i][j] = { i, j, tVal, false };
				targetVal = max(targetVal, tVal);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j].value != targetVal) continue;
				map[i][j].visited = true;
				run(map[i][j], 1, K);
				map[i][j].visited = false;
			}
		}

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}