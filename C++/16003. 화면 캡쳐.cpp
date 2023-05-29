#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, C;
string msg = "0123456789";

int len(int n) {
	int len = 0;
	while (n != 0) {
		n = n / 10;
		++len;
	}
	return len;
}

void run(int lv, string str) {

	if (lv == M) return;

	for (int i = 0; i < 10; i++) {
		if (lv == 0 && i == 0) continue;
		string temp = str + msg[i];
		if (stoi(temp) > N) continue;
		if (++C > 50) return;
		cout << temp << ".png ";
		run(lv + 1, temp);
	}
}

int main()
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
		cin >> N;
		M = len(N);
		C = 0;

		cout << "#" << test_case << " ";
		run(0, "");
		cout << "\n";
		
	}
	return 0;
}