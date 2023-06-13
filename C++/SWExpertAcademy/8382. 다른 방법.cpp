#include <iostream>
#include <algorithm>

using namespace std;

int f(int n) {
	if (n <= 1) return n;

	return f(n - 2) + 4;
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
		int startX, startY;
		int endX, endY;

		cin >> startX >> startY;
		cin >> endX >> endY;

		endX = abs(endX - startX);
		endY = abs(endY - startY);

		int maxVal = max(endX, endY);
		int minVal = min(endX, endY);
		int diff = maxVal - minVal;

		//int result = 2 * maxVal - (diff % 2);
		int result = f(diff) + 2 * minVal;

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}