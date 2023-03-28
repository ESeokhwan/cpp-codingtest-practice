#include <bits/stdc++.h>
using namespace std;

int n;
int eggs[8][2];
int res;

void dfs(int idx) {
  if(idx == n) {
	int cnt = 0;
	for(int i = 0; i < n; i++) if(eggs[i][0] == 0) cnt++;

	res = max(res, cnt);
	return;
  }
  if(eggs[idx][0] == 0) {
	dfs(idx+1);
	return;
  }

  bool is_update = false;
  for(int i = 0; i < n; i++) {
	if(i == idx) continue;
	if(eggs[i][0] == 0) continue;

	int old_val1 = eggs[idx][0];
	int old_val2 = eggs[i][0];

	eggs[idx][0] = max(0, eggs[idx][0] - eggs[i][1]);
	eggs[i][0] = max(0, eggs[i][0] - eggs[idx][1]);
	
	dfs(idx + 1);

	eggs[idx][0] = old_val1;
	eggs[i][0] = old_val2;
	is_update = true;
  }
  if(!is_update) dfs(n);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  res = 0;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> eggs[i][0] >> eggs[i][1];

  dfs(0);
  cout << res << "\n";
  return 0;
}
