#include <bits/stdc++.h>
using namespace std;

int t, n, rt, x, y;
vector<int> children[10000];
bool is_root[10000];
int dp[10000][2];

int contains_x(int cur_rt) {
  if(dp[cur_rt][0] != -1) return dp[cur_rt][0];

  if(cur_rt == x) {
	dp[cur_rt][0] = 1;
	return dp[cur_rt][0];
  }

  for(int child : children[cur_rt]) {
	if(contains_x(child) == 1) dp[cur_rt][0] = 1;
  }
  if(dp[cur_rt][0] == -1) dp[cur_rt][0] = 0;
  return dp[cur_rt][0];
}

int contains_y(int cur_rt) {
  if(dp[cur_rt][1] != -1) return dp[cur_rt][1];

  if(cur_rt == y) {
	dp[cur_rt][1] = 1;
	return dp[cur_rt][1];
  }

  for(int child : children[cur_rt]) {
	if(contains_y(child) == 1) dp[cur_rt][1] = 1;
  }
  if(dp[cur_rt][1] == -1) dp[cur_rt][1] = 0;
  return dp[cur_rt][1];
}

int find() {
  memset(dp, -1, sizeof(dp));
  int cur_rt = rt;
  while(true) {
	bool has_child = false;
	for(int child : children[cur_rt]) {
	  if(contains_x(child) && contains_y(child)) {
		cur_rt = child;
		has_child = true;
	  }
	}
	if(!has_child) return cur_rt;
  }
}

void solution() {
  int a, b;
  cin >> n;
  memset(is_root, true, sizeof(is_root));
  for(int i = 0; i < n - 1; i++) {
	cin >> a >> b;
	children[a - 1].push_back(b - 1);
	is_root[b - 1] = false;
  }
  for(int i = 0; i < n - 1; i++) {
	if(is_root[i]) {
	  rt = i;
	  break;
	}
  }
  cin >> a >> b;
  x = a - 1;
  y = b - 1;
  cout << find() + 1<< "\n";
  
  for(int i = 0; i < n; i++) {
	children[i].clear();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  for(int i = 0 ; i < t; i++) {
	solution();
  }
  return 0;
}
