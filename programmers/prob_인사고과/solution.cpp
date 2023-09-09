#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp (vector<int> a, vector<int> b) { 
    if(a[0] == b[0]) {
        return a[1] > b[1];
    }
    return (a[0] > b[0]);
}

bool cmp2(vector<int> a, vector<int> b) { 
    return a[0] + a[1] > b[0] + b[1];
}

int solution(vector<vector<int>> scores) {
    for(int i = 0; i < scores.size(); i++) scores[i].push_back(i);
    sort(scores.begin(), scores.end(), cmp);
    
    int max_second = 0;
    int tmp_max_second = 0;
    int prev = 10000000;
    for(int i = 0; i < scores.size(); i++) {
        if(prev > scores[i][0]) {
            max_second = max(max_second, tmp_max_second);
            tmp_max_second = 0;
        }
        if(max_second > scores[i][1]) {
            scores[i][2] = -1;
        }
        tmp_max_second = max(tmp_max_second, scores[i][1]);
        prev = scores[i][0];
    }
    sort(scores.begin(), scores.end(), cmp2);
    
    int cur_rank = 0;
    int next_rank = 1;
    prev = 10000000;
    bool not_found = true;
    for(int i = 0; i < scores.size(); i++) {
        // cout << scores[i][0] << " " << scores[i][1] << " " << scores[i][2] << "\n";
        if(scores[i][2] == -1) continue;
        
        int score = scores[i][0] + scores[i][1];
        if(score < prev) {
            prev = score;
            cur_rank = next_rank;
        }
        if(scores[i][2] == 0) {
            not_found = false;
            break;
        }
        next_rank += 1;
    }
    
    int answer = cur_rank;
    if(not_found) answer = -1;
    return answer;
}
