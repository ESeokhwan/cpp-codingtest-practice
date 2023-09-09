#include <string>
#include <vector>

using namespace std;

pair<int, int> dp[100005];

pair<int, int> getGood(pair<int, int> a, pair<int, int> b) {
    if(a.first < b.first) {
        return a;
    } else if(a.first > b.first) {
        return b;
    } else {
        if(a.second >= b.second) {
            return a;
        } else {
            return b;
        }
    }
}

pair<int, int> gofd(int x) {
    if(dp[x].first != -1 || dp[x].second != -1) return dp[x];
    
    if(x == 0) {
        dp[x] = { 0, 0 };
        return dp[x];
    }
    
    pair<int, int> tmp_dp = { 10000000, 0 };
    if(x >= 50) {
        tmp_dp = getGood(
            tmp_dp, 
            {gofd(x - 50).first + 1, gofd(x - 50).second + 1}
        );
    }
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 20; j++) {
            int rem = i * j;
            if(x < rem) break;
            if(i == 1) {
                tmp_dp = getGood(
                    tmp_dp, 
                    { gofd(x - rem).first + 1, gofd(x - rem).second + 1 }
                );
            } else {
                tmp_dp = getGood(
                    tmp_dp, 
                    { gofd(x - rem).first + 1, gofd(x - rem).second }
                );
            }
        }
    }
    dp[x] = tmp_dp;
    return dp[x];
}

vector<int> solution(int target) {
    for(int i = 0; i < 100005; i++) {
        dp[i] = { -1, -1 };
    }
    
    vector<int> answer;
    answer.push_back(gofd(target).first);
    answer.push_back(gofd(target).second);
    return answer;
}
