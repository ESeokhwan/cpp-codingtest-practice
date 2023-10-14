#include <bits/stdc++.h>
using namespace std;

int t;
int k;
int nums[500];
pair<int, int> dp[500][500];

pair<int, int> gofd(int st, int en) {
  if(dp[st][en].first != -1) return dp[st][en];

  if(st == en) dp[st][en] = make_pair(nums[st], 0);
  else {
	int page = gofd(st, st).first + gofd(st + 1, en).first;
	int minVal = gofd(st, st).second + gofd(st + 1, en).second + gofd(st, st).first + gofd(st + 1, en).first;
	for(int i = st; i < en; i++) {
	  int tmpVal = gofd(st, i).second + gofd(i + 1, en).second + gofd(st, i).first + gofd(i + 1, en).first;
	  minVal = min(minVal, tmpVal);
	}
	dp[st][en] = make_pair(page, minVal);
  }
  return dp[st][en];
}

void solution() {
  cin >> k;
  for(int i = 0; i < k; i++) {
	cin >> nums[i];
  }

  for(int i = 0; i < 500; i++) {
	for(int j = 0; j < 500; j++) {
	  dp[i][j] = {-1, -1};
	}
  }
  cout << gofd(0, k - 1).second << "\n";;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  for(int i = 0; i < t; i++) solution();

  return 0;
}
