#include <bits/stdc++.h>
using namespace std;

int n, m;

bool _map[50][50];
bool is_cleaned[50][50];

int cr, cc, cd;

pair<int, int> dirs[4] = {
  make_pair(-1, 0),
  make_pair(0, 1),
  make_pair(1, 0),
  make_pair(0, -1)
};


bool move() {
  is_cleaned[cr][cc] = true;
  bool is_all_cleaned = true;
  for(int i = 0; i < 4; i++) {
	int nr = cr + dirs[i].first;
	int nc = cc + dirs[i].second;

	if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
	if(_map[nr][nc]) continue;
	if(!is_cleaned[nr][nc]) {
	  is_all_cleaned = false;
	  break;
	}
  }

  if(is_all_cleaned) {
	int nr = cr - dirs[cd].first;
	int nc = cc - dirs[cd].second;

	if(nr < 0 || nr >= n || nc < 0 || nc >= m) return false;
	if(_map[nr][nc]) return false;
	cr = nr;
	cc = nc;
	return true;
  } else {
	cd = (cd + 3) % 4;
	int nr = cr + dirs[cd].first;
	int nc = cc + dirs[cd].second;
	if(nr < 0 || nr >= n || nc < 0 || nc >= m) return true;
	if(_map[nr][nc]) return true;
	if(is_cleaned[nr][nc]) return true;

	cr = nr;
	cc = nc;
	return true;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(is_cleaned, false, sizeof(is_cleaned));

  cin >> n >> m;
  cin >> cr >> cc >> cd;

  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) cin >> _map[i][j];
  }

  while(move()) {
  }

  int res = 0;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	  if(is_cleaned[i][j]) res++;
	}
  }
  cout << res << "\n";
  return 0;
}
