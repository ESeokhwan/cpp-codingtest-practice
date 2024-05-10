#include <bits/stdc++.h>
using namespace std;

int n;

int rt[301];

priority_queue<
  pair<int, pair<int, int> >,
  vector<pair<int, pair<int, int> > >,
  greater<pair<int, pair<int, int> > >
> pq;

void ds_init() {
  for (int i = 0; i <= 300; i++) {
	rt[i] = i;
  }
}

int ds_find(int x) {
  if (rt[x] == x) return x;
  return ds_find(rt[x]);
}

int ds_union(int x, int y) {
  int rt_x = ds_find(x);
  int rt_y = ds_find(y);
  if (rt_x == rt_y) {
	return -1;
  }
  rt[rt_x] = rt_y;
  return 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  int tmp;
  for (int i = 1; i <= n; i++) {
	cin >> tmp;
	pq.push(make_pair(tmp, make_pair(i, 0)));
	pq.push(make_pair(tmp, make_pair(0, i)));
  }
  
  ds_init();
  for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= n; j++) {
	  cin >> tmp;
	  pq.push(make_pair(tmp, make_pair(i, j)));
	}
  }

  int cnt = 0;
  int ans = 0;
  while(!pq.empty() && cnt < n) {
	int cur_d = pq.top().first;
	int cur_r = pq.top().second.first;
	int cur_c = pq.top().second.second;
	pq.pop();

	if (ds_union(cur_r, cur_c) == -1) continue;
	ans += cur_d;
	cnt += 1;
  }

  cout << ans << "\n";
  return 0;
}
