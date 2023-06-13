#include <iostream>
#include <algorithm>

using namespace std;

int *numList; // 숫자 리스트
int operList[4]; // 연산자 리스트 + - * /
int N; // 숫자 리스트 사이즈
int maxVal;
int minVal;

void run(int lv, int sum) {
	if (lv == N) {
		maxVal = max(maxVal, sum);
		minVal = min(minVal, sum);
		return;
	}

	// 4개의 연산자 중에서 선택
	for (int i = 0; i < 4; i++) {
		if (operList[i] == 0) continue; // 남은 연산자 갯수가 없어 돌아가!!

		int newSum; // sum의 원형을 훼손시키면 안됌
		switch (i) {
			case 0:
				newSum = sum + numList[lv];
				break;
			case 1:
				newSum = sum - numList[lv];
				break;
			case 2:
				newSum = sum * numList[lv];
				break;
			case 3:
				newSum = sum / numList[lv];
				break;
		}

		operList[i] = operList[i] - 1; // 사용한 연산자 갯수 감소
		run(lv + 1, newSum);
		operList[i] = operList[i] + 1; // 다시 원래대로
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
		int tVal;

		cin >> N;

		numList = new int[N] {0}; // 0으로 N개 초기화 (동적으로 할당)

		maxVal = -21e8; // 최대값 초기화
		minVal = 21e8; // 최소값 초기화

		// 입력 받기
		for (int i = 0; i < 4; i++) cin >> operList[i];
		for (int i = 0; i < N; i++) cin >> numList[i];

		// 시작 맨 처음 나오는 숫자가 초기값
		// 시작 숫자가 고정되어 있다
		run(1, numList[0]);

		cout << "#" << test_case << " " << maxVal - minVal << "\n";
	}
	return 0;
}