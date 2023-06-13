#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int end = 0;
    
    sort(targets.begin(), targets.end(), compare);

    for(vector<int> target : targets){
        if(target[0] < end) continue;
        answer++;
        end = target[1];
    }
    
    return answer;
}