#include <bits/stdc++.h>
using namespace std;

int n;
int employee[50];
vector<int> children[50];
int dp[50];

int gofd(int x) {
  if(dp[x] != -1) return dp[x];

  dp[x] = 0;
  vector<int> children_gofd;
  for(int child : children[x]) {
	children_gofd.push_back(-1 * gofd(child));
  }
  sort(children_gofd.begin(), children_gofd.end());
  for(int i = 0; i < children_gofd.size(); i++) {
	dp[x] = max(dp[x], 1 + i - children_gofd[i]);
  }
  return dp[x];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));
  cin >> n;
  for(int i = 0; i < n; i++) {
	cin >> employee[i];
	if(employee[i] != -1) children[employee[i]].push_back(i);
  }

  cout << gofd(0) << "\n";
  return 0;
}
