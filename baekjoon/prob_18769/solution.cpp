#include <bits/stdc++.h>
using namespace std;

int t;
int R, C;

int rt[250005];
int rk[250005];

void ds_init() {
  memset(rt, -1, sizeof(rt));
  memset(rk, 0, sizeof(rk));
}

int ds_find(int x) {
  if (rt[x] == -1 || rt[x] == x) return (rt[x] = x);
  return (rt[x] = ds_find(rt[x]));
}

int ds_union(int x, int y) {
  int rt_x = ds_find(x);
  int rt_y = ds_find(y);
  if (rt_x == rt_y) return 0;

  if (rk[rt_x] > rk[rt_y]) {
	rt[rt_y] = rt_x;
  } else if (rk[rt_x] < rk[rt_y]) {
	rt[rt_x] = rt_y;
  } else {
	rt[rt_y] = rt_x;
	rk[rt_x] += 1;
  }
  return 1;
}

void solution() {
  int tmp_input;
  ds_init();
  vector<int> edges[250005];
  priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
	for (int j = 0; j < C - 1; j++) {
	  cin >> tmp_input;
	  pq.push({tmp_input, { C * i + j, C * i + j + 1 } });
	}
  }
  for (int i = 0; i < R - 1; i++) {
	for (int j = 0; j < C; j++) {
	  cin >> tmp_input;
	  pq.push({tmp_input, { C * i + j, C * (i + 1) + j } });
	}
  }

  int res = 0;
  int cnt = 0;
  while (!pq.empty()) {
	if (cnt == R * C - 1) break;
	int dist = pq.top().first;
	int st = pq.top().second.first;
	int en = pq.top().second.second;
	pq.pop();
	if (ds_union(st, en) == 1) {
	  cnt += 1;
	  res += dist;
	}
  }
  cout << res << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  for (int i = 0; i < t; i++) {
	solution();
  }
  return 0;
}

