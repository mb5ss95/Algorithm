#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct node {
	int y;
	int x;
	int val;
	int turn;
	bool visited;
};

bool isValid(int now, int next, int d) {
	vector<vector<vector<int>>> valid = {
		{
			{0, 2, 3, 4},
			{0, 1, 4, 5},
			{0, 2, 5, 6},
			{0, 1, 3, 6}
		},
		{
			{0, 1, 4, 5},
			{0, 1, 3, 6}
		},
		{
			{0, 2, 3, 4},
			{0, 2, 5, 6}
		},
		{
			{0, 1, 4, 5},
			{0, 2, 5, 6}
		},
		{
			{0, 2, 5, 6},
			{0, 1, 3, 6}
		},
		{
			{0, 2, 3, 4},
			{0, 1, 3, 6}
		},
		{
			{0, 2, 3, 4},
			{0, 1, 4, 5}
		}
	};

	for (int i = 0; i < valid[now][d].size(); i++) {
		if (next == valid[now][d][i]) return false;
	}
	return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<vector<int>> dy = {
			{0, -1, 0, 1},
			{-1, 1},
			{0, 0},
			{-1, 0},
			{0, 1},
			{0, 1},
			{0, -1}
		};
		vector<vector<int>> dx = {
			{-1, 0, 1, 0},
			{0, 0},
			{-1, 1},
			{0, 1},
			{1, 0},
			{-1, 0},
			{-1, 0}
		};

		int N, M, R, C, K, tVal;
		cin >> N >> M >> R >> C >> K;

		vector<vector<node>> map(N, vector<node>(M));
		queue<node> q;
		int result = 1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> tVal;
				map[i][j] = { i, j, tVal-1, 1, false };
			}
		}
		
		map[R][C].visited = true;
		q.push(map[R][C]);

		while (!q.empty()) {
			node now = q.front();
			q.pop();

			for (int i = 0; i < dy[now.val].size(); i++) {
				int ny = dy[now.val][i] + now.y;
				int nx = dx[now.val][i] + now.x;

				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				node next = map[ny][nx];
				if (isValid(now.val, next.val, i)) continue;
				if (next.val < 0) continue;
				if (next.visited) continue;
				next.turn = now.turn + 1;
				if (next.turn > K) continue;
				next.visited = true;
				map[ny][nx] = next;
				result++;
				q.push(next);
			}
		}

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}