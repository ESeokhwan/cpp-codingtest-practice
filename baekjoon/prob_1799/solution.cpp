#include <bits/stdc++.h>
using namespace std;

int n;
bool _map[10][10];
vector<pair <int, int> > bishops;

int res;

bool is_safe(int r, int c) {
  for(auto bi : bishops) {
	int off_r = r - bi.first;
	int off_c = c - bi.second;
	
	if((abs(off_r) == abs(off_c))) return false;
  }
  return true;
}

void dfs(int acc, int idx) {
  if(idx == 2 * n - 1) {
	res = max(acc, res);
	return;
  }

  int sr, sc;
  if(idx <= n - 1) {
	sr = idx;
	sc = 0;
  } else {
	sr = n - 1;
	sc = idx - (n - 1);
  }

  bool is_updated = false;
  for(int i = 0; i < min(idx + 1, 2 * n - (idx + 1)); i++) {
	int r = sr - i;
	int c = sc + i;
	if(!_map[r][c]) continue;
	if(!is_safe(r, c)) continue;

	is_updated = true;
	bishops.push_back(make_pair(r, c));
	dfs(acc+1, idx + 1);
	bishops.pop_back();
  }
  if(!is_updated) dfs(acc, idx + 1);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  res = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) cin >> _map[i][j];
  }

  dfs(0, 0);

  cout << res << "\n";
  return 0;
}
