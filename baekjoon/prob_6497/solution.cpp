#include <bits/stdc++.h>
using namespace std;

int n, m;
priority_queue< pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

int ds_rt[200005];
int ds_rk[200005];

void ds_init() {
  for(int i = 0; i < 200005; i++) {
	ds_rt[i] = i;
	ds_rk[i] = 0;
  }
}

int ds_find(int x) {
  if (ds_rt[x] == x) return x;
  return (ds_rt[x] = ds_find(ds_rt[x]));
}

int ds_union(int x, int y) {
  int rt_x = ds_find(x);
  int rt_y = ds_find(y);
  if (rt_x == rt_y) return false;

  if (ds_rk[rt_x] > ds_rk[rt_y]) {
	ds_rt[rt_y] = rt_x;
  } else if (ds_rk[rt_x] > ds_rk[rt_y]) {
	ds_rt[rt_x] = rt_y;
  } else {
	ds_rt[rt_y] = rt_x;
	ds_rk[rt_x] += 1;
  }
  return true;
}

bool solution() {
  ds_init();
  cin >> m >> n;
  if (n == 0 && m == 0) return false;

  int total_cost = 0;
  for (int i = 0; i < n; i++) {
	int input1, input2, input3;
	cin >> input1 >> input2 >> input3;
	pq.push( { input3, { input1, input2 } } );
	total_cost += input3;
  }

  int cnt = 0;
  int cost = 0;
  while (cnt < m && !pq.empty()) {
	auto road_info = pq.top();
	pq.pop();
	if (ds_union(road_info.second.first, road_info.second.second)) {
	  cnt += 1;
	  cost += road_info.first;
	}
  }

  cout << total_cost - cost << "\n";
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while(solution()) { }
  return 0;
}
