#include <bits/stdc++.h>
using namespace std;

int t, n, k, w;

int d[1001];
vector<int> nx[1001];
int off_first[1001];
queue<int> q;

int dp[1001];

void solution() {
  memset(off_first, 0, sizeof(off_first));

  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
	cin >> d[i];
	dp[i] =  d[i];
  }

  for(int i = 1; i <= k; i++) {
	int input[2];
	cin >> input[0] >> input[1];
	nx[input[0]].push_back(input[1]);
	off_first[input[1]]++;
  }
  cin >> w;

  for(int i = 1; i <= n;i++) {
	if(off_first[i] == 0) q.push(i);
  }

  while(!q.empty()) {
	int cur = q.front();
	q.pop();
	for(int i = 0; i < nx[cur].size(); i++) {
	  int tar = nx[cur][i];
	  dp[tar] = max(dp[tar], dp[cur] + d[tar]);
	  off_first[tar] -= 1;
	  if(off_first[tar] == 0) q.push(tar);
	}
  }

  for(int i = 1; i <= n; i++) nx[i].clear();

  cout << dp[w] << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  for(int i = 0; i < t; i++) solution();
  return 0;
}
