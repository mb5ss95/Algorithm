#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;


struct node {
	int y;
	int x;
	int lv;
};

struct home {
	int value;
	int num;
};

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int len;
int startY;
int startX;
int N, M;


vector<vector<bool>> makeDP(vector<vector<bool>> dp, int startY, int startX, int lv) {
	queue<node> q;
	q.push({ startY, startX, 1 });
	dp[startY][startX] = true;

	while (!q.empty()) {
		node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;

			if (ny < 0 || nx < 0 || ny >= dp.size() || nx >= dp.size()) continue;
			if (dp[ny][nx]) continue;
			
			dp[ny][nx] = true;

			if (now.lv + 1>= lv) continue;
			q.push({ny, nx, now.lv + 1});
		}
	}

	return dp;
}

bool compare(home a, home b) {

	return a.num > b.num;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test_case;
	int T;
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int tVal;
		cin >> N >> M;

		vector<vector<int>> map(N, vector<int>(N, 0));
		vector<home> homes;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> tVal;
				map[i][j] = tVal;
			}
		}
		int cost, count, ny, nx, nyy, nxx, value;
		int check = 0;
		for (int k = 1; k < N+2; k++) {
			len = 2 * k - 1;
			vector<vector<bool>> dp(len, vector<bool>(len, false));
			//운영 비용 = K * K + (K - 1) * (K - 1)
			cost = k * k + (k - 1) * (k - 1);
			
			startY = k - 1;
			startX = k - 1;
			dp = makeDP(dp, startY, startX, k);

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					count = 0;
					ny = i - startY;
					nx = j - startX;
					for (int k = 0; k < len; k++) {
						for (int z = 0; z < len; z++) {
							nyy = k + ny;
							nxx = z + nx;
							if (nyy < 0 || nxx < 0 || nyy >= N || nxx >= N) continue;
							if (dp[k][z] && map[nyy][nxx]) {
								count++;
							}
						}
					}
					value = count * M - cost;
					if (value < 0) continue;
					if (check < count){
						check = count;
						homes.push_back({ value, count });
					}
				}
			}
		}
		sort(homes.begin(), homes.end(), compare);
		for (int i = 0; i < homes.size(); i++) {
			if (homes[i].value < 0) continue;
			cout << "#" << test_case << " " << homes[i].num << "\n";
			break;
		}
	}
	return 0;
}