#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> lis[10000];
int prev_cnt[10000];
int t[10000];

int to_gph[10000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(prev_cnt, 0, sizeof(prev_cnt));
  memset(to_gph, -1, sizeof(to_gph));

  cin >> n;
  for(int i = 0; i < n; i++) {
	int m;
	cin >> t[i] >>  m;
	prev_cnt[i] = m;
	for(int j = 0; j < m; j++) {
	  int input;
	  cin >> input;
	  lis[input - 1].push_back(i);
	}
  }

  queue<int> q;
  for(int i = 0; i < n; i++) {
	if(prev_cnt[i] == 0) {
	  to_gph[i] = t[i];
	  q.push(i);
	}
  }

  while(!q.empty()) {
	int cur = q.front();
	q.pop();
	for(int nx_job : lis[cur]) {
	  to_gph[nx_job] = max(to_gph[nx_job], to_gph[cur] + t[nx_job]);
	  prev_cnt[nx_job]--;
	  if(prev_cnt[nx_job] == 0) q.push(nx_job);
	}
  }

  int res = 0;
  for(int i = 0; i < n; i++) res = max(res, to_gph[i]);

  cout << res << "\n";
  return 0;
}
