#include <bits/stdc++.h>
#include <tuple>
using namespace std;

int rt[100000];
int rk[100000];

void ds_init() {
  for(int i = 0; i < 100000; i++) {
	rt[i] = i;
	rk[i] = 0;
  }
}

int ds_find(int x) {
  if(x == rt[x]) return x;
  return rt[x] = ds_find(rt[x]);
}

bool ds_union(int x, int y) {
  int rt_x = ds_find(x);
  int rt_y = ds_find(y);
  if(rt_x == rt_y) return false;
  if(rk[rt_x] > rk[rt_y]) {
	rt[rt_y] = rt_x;
  } else {
	if(rk[rt_x] == rk[rt_y]) rk[rt_y]++;
	rt[rt_x] = rt_y;
  }
  return true;
}

int n;
pair<int, int> po_x[100000];
pair<int, int> po_y[100000];
pair<int, int> po_z[100000];

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int > > > edges;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ds_init();
  cin >> n;
  for(int i = 0; i < n; i++) {
	cin >> po_x[i].first >> po_y[i].first >> po_z[i].first;
	po_x[i].second = i;
	po_y[i].second = i;
	po_z[i].second = i;
  }

  sort(po_x, po_x + n);
  sort(po_y, po_y + n);
  sort(po_z, po_z + n);

  for(int i = 0; i < n-1; i++) {
	edges.push(
		make_tuple(po_x[i+1].first - po_x[i].first, po_x[i+1].second, po_x[i].second));
	edges.push(
		make_tuple(po_y[i+1].first - po_y[i].first, po_y[i+1].second, po_y[i].second));
	edges.push(
		make_tuple(po_z[i+1].first - po_z[i].first, po_z[i+1].second, po_z[i].second));
  }

  int res = 0;
  int cnt = 0;
  while(cnt < n-1) {
	auto e = edges.top();
	int val = get<0>(e);
	int a = get<1>(e);
	int b = get<2>(e);
	edges.pop();

	if(ds_union(a, b)) {
	  cnt += 1;
	  res += val;
	}
  }

  cout << res << "\n";
  return 0;
}
