#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int y;
	int x;
	int val;
	bool visited;
};
node **map;
int N, result;
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };

void run(node now, int count, int k) {
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + now.y;
		int nx = dx[i] + now.x;

		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		node next = map[ny][nx];

		if (next.visited) continue;
		if (now.val > next.val) {
			map[ny][nx].visited = true;
			run(next, count + 1, k);
		}
		else {
			if ((next.val - now.val) >= k) continue;
			else {
				map[ny][nx].visited = true;
				int rest = next.val - now.val + 1;
				map[ny][nx].val = map[ny][nx].val - rest;
				run(map[ny][nx], count + 1, 0);
				map[ny][nx].val = map[ny][nx].val + rest;
			}
		}

		map[ny][nx].visited = false;
	}
	result = max(result, count);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int tVal, K, startLV;
		cin >> N >> K;

		startLV = 0;
		result = 0;
		map = new node *[N];

		for (int i = 0; i < N; i++) {
			map[i] = new node[N];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> tVal;
				startLV = max(tVal, startLV);
				map[i][j] = { i, j, tVal, false };
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j].val != startLV) continue;
				map[i][j].visited = true;
				run(map[i][j], 1, K);
				map[i][j].visited = false;
			}
		}

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}