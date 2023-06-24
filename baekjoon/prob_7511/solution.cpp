#include <bits/stdc++.h>
using namespace std;

int n, k, m;
int a, b, u, v;
int t;

int rt[1000000];
int rk[1000000];

void ds_init() {
  for(int i = 0; i < n; i++) {
	rt[i] = i;
	rk[i] = 0;
  }
}

int ds_find(int x) {
  if(rt[x] == x) return x;
  return (rt[x] = ds_find(rt[x]));
}

bool ds_union(int x, int y) {
  int rt_x = ds_find(x);
  int rt_y = ds_find(y);
  if(rt_x == rt_y) return false;
  
  if(rk[rt_x] > rk[rt_y]) {
	rt[rt_y] = rt_x;
  } else if(rk[rt_y] > rk[rt_x]) {
	rt[rt_x] = rt_y;
  } else {
	rt[rt_y] = rt_x;
	rk[rt_x] += 1;
  }
  return true;
}

void solution() {
  cin >> n >> k;
  ds_init();
  for(int i = 0; i < k; i++) {
	cin >> a >> b;
	ds_union(a, b);
  }

  cin >> m;
  for(int i = 0; i < m; i++) {
	cin >> u >> v;
	if(ds_find(u) == ds_find(v)) cout << "1\n";
	else cout << "0\n";
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> t;
  for(int i = 0; i < t; i++) {
	cout << "Scenario " << i + 1 << ":\n";
	solution();
	cout << "\n";
  }
  return 0;
}
