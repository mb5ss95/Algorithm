#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int directY[4] = { -1, 1, 0, 0 };
int directX[4] = { 0, 0, 1, -1 };
struct Node { int y, x; };
queue<Node> q;
int h, w;

int bfs(vector<vector<int>> &picture, int dy, int dx) {
    while (!q.empty()) q.pop();

    int cnt = 1;
    q.push({ dy, dx });
    int tar = picture[dy][dx];
    picture[dy][dx] = 0;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        
        for (int t = 0; t < 4; t++) {
            int ny = now.y + directY[t];
            int nx = now.x + directX[t];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (picture[ny][nx] != tar) continue;
            picture[ny][nx] = 0;
            q.push({ ny, nx });
            cnt++;
        }
    }

    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    h = m;
    w = n;

    int sumCnt = 0;    
    int maxi = -3423;
    
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (picture[y][x] == 0) continue;
            int ret = bfs(picture, y, x);
            maxi = max(maxi, ret);
            sumCnt++;
        }
    }

    vector<int> answer(2);
    answer[0] = sumCnt;
    answer[1] = maxi;
    return answer;
}