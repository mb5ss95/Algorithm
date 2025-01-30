#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> nodeList;
vector<bool> checkList;
int N, M, V;

void dfs(int from, vector<int> &visited) {
    checkList[from] = true;
    visited.push_back(from);

    for (int i = 0; i < nodeList[from].size(); i++) {
        int to = nodeList[from][i];
        if (checkList[to]) continue;

        dfs(to, visited);
    }
}

void bfs(int first, vector<int>& visited) {
    checkList[first] = true;

    queue<int> q;
    q.push(first);

    while (!q.empty()) {
        int from = q.front();
        q.pop();

        visited.push_back(from);

        for (int i = 0; i < nodeList[from].size(); i++) {
            int to = nodeList[from][i];
            if (checkList[to]) continue;
            checkList[to] = true;

            q.push(to);
        }
    }
}

void printResult(vector<int>& visited) {
    for (int i : visited) {
        cout << i << " ";
    }
    cout << "\n";

    visited.clear();
    checkList = vector<bool>(N + 1);
}

int main(void)
{
    freopen_s(new FILE*, "input.txt", "r", stdin);

    cin >> N >> M >> V;
    nodeList = vector<vector<int>>(N + 1);
    checkList = vector<bool>(N + 1);

    int from, to;
    for (int j = 0; j < M; j++) {
        cin >> from >> to;

        nodeList[from].push_back(to);
        nodeList[to].push_back(from);
    }

    for_each(nodeList.begin(), nodeList.end(), [](vector<int>& vec) {sort(vec.begin(), vec.end()); });

    vector<int> visited;
    dfs(V, visited);
    printResult(visited);

    bfs(V, visited);
    printResult(visited);

    return 0;
}