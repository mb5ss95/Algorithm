#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
    int s, e;
};

bool compare(node a, node b){
    if((a.e - a.s) == (b.e - b.s)) return a.s<b.s;
    
    return (a.e - a.s) < (b.e - b.s);
}

vector<int> solution(vector<int> sequence, int k) {
    vector<node> answer;
    int result = 0;
    int left = 0;
    int right = -1;
    
    while(1){
        if(result < k){
            if(++right >= sequence.size()) break;
            result = result + sequence[right];
        }
        else{
            result = result - sequence[left];
            if(left++ >= sequence.size()) break;
        }
        if(result == k){
            answer.push_back({left, right});
        }
    }
    
    sort(answer.begin(), answer.end(), compare);
    
    return {answer[0].s, answer[0].e};
}