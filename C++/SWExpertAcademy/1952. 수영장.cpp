#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 1일 1달 3달 1년
// 10원, 40원, 100원, 300

char chs[] = { 'd', 'm', 't' };
int values[4];
int plan[12];
int result;
int visited[12];

void run(int lv, string sum) {
	if (lv >= 12) {
		int cost = 0;
		for (int i = 0; i < 12; i++) {
			if (plan[i] == 0) continue;
			if (sum[i] == 'd') {
				cost = cost + (plan[i] * values[0]);
			}
			else if (sum[i] == 'm') {
				cost = cost + values[1];
			}
			else if (sum[i] == 't') {
				cost = cost + values[2];
				i = i + 2;
			}
		}
		result = min(result, cost);
		return;
	}

	for (int i = 0; i < 3; i++) {
		char ch = chs[i];
		if (ch == 'd') {
			run(lv + 1, sum + ch);
		}
		else if (ch == 'm') {
			run(lv + 1, sum + ch);
		}
		else if (ch == 't') {
			run(lv + 3, sum + "ttt");
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 123123123;
		for (int i = 0; i < 4; i++) cin >> values[i];
		for (int i = 0; i < 12; i++) cin >> plan[i];

		visited[0] = 1;
		run(0, "");
		result = min(result, values[3]);
		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}