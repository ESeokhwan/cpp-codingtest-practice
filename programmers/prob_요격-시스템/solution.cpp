#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue> 

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if(a[1] == b[1]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    bool visited[500003];
    for(int i = 0; i < 500003; i++) visited[i] = false;
    
    sort(targets.begin(), targets.end(), cmp);
    for(int i = 0; i < targets.size(); i++) pq.push({ targets[i][0], i });
    
    int answer = 0;
    for(int i = 0; i < targets.size(); i++) {
        if(visited[i]) continue;
        while(!pq.empty() && pq.top().first < targets[i][1]) {
            visited[pq.top().second] = true;
            pq.pop();
        }
        answer += 1;
    }
    return answer;
}
