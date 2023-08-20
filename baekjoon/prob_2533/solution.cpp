#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> children[1000000];
bool visited[1000000];
int dp[1000000][2];

int calc(int root, int is_root_ea) {
  if(dp[root][is_root_ea] != -1) return dp[root][is_root_ea];
  dp[root][is_root_ea] = 0;
  visited[root] = true;
  if(is_root_ea == 1) {
	dp[root][is_root_ea] += 1;
	for(int i = 0; i < children[root].size(); i++) {
	  if(visited[children[root][i]]) continue;
	  dp[root][is_root_ea] += min(calc(children[root][i], 0), calc(children[root][i], 1));
	}
  } else {
	for(int i = 0; i < children[root].size(); i++) {
	  if(visited[children[root][i]]) continue;
	  dp[root][is_root_ea] += calc(children[root][i], 1);
	}
  }
  visited[root] = false;
  return dp[root][is_root_ea];
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(dp, -1, sizeof(dp));
  memset(visited, false, sizeof(visited));

  cin >> n;
  for(int i = 0; i < n - 1; i++) {
	int a, b;
	cin >> a >> b;

	children[a - 1].push_back(b - 1);
	children[b - 1].push_back(a - 1);
  }

  int root = 0;
  cout << min(calc(root, true), calc(root, false)) << "\n";
  return 0;
}
