#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int x = 0;
	int y = 0;
	int weight = 0;
	bool isAvailable = false;

	Node() {}

	Node(int x, int y, int weight, bool isAvailable)
		: x(x), y(y), weight(weight), isAvailable(isAvailable) {}

	Node(int x, int y, int weight)
		: x(x), y(y), weight(weight) {}
};

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	Node** map; // 2차원 맵
	int row, col; // 맵의 세로 & 가로 크기
	int dy[] = { -1, 0, 1, 0 };
	int dx[] = { 0, 1, 0, -1 };

	cin >> row >> col;

	map = new Node * [row] {};
	for (int i = 0; i < row; i++) {
		map[i] = new Node[col]{};
		for (int j = 0; j < col; j++) {
			char input = cin.get();

			while (input == '\n') {
				input = cin.get();
			}

			map[i][j] = { i, j, 2134567890, (input == '1') };
		}
	}

	queue<Node> q;
	map[0][0].weight = 1;
	Node currentNode = { 0, 0, 1 };
	q.push(currentNode); // 시작점 설정

	while (!q.empty()) {
		Node node = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = node.y + dy[i];
			int nx = node.x + dx[i];

			if (ny < 0 || ny >= row || nx < 0 || nx >= col) continue;
			if (!map[ny][nx].isAvailable) continue;

			int nWeight = node.weight + 1;
			if (nWeight >= map[ny][nx].weight) continue;
			map[ny][nx].weight = nWeight;

			q.push({ nx, ny, nWeight });
		}
	}

	cout << map[row - 1][col - 1].weight << "\n";

	// 메모리 해제
	for (int i = 0; i < row; i++) {
		delete[] map[i];
	}
	delete[] map;

}