#include <bits/stdc++.h>

using namespace std;

int rt[500000];
int rk[500000];

void init_ds() {
  memset(rt, -1, sizeof(rt));
  memset(rk, 0, sizeof(rk));
}

int find(int x) {
  if(rt[x] == -1) return x;
  return (rt[x] = find(rt[x]));
}

bool uni(int x, int y) {
  int rt_x = find(x);
  int rt_y = find(y);

  if(rt_x == rt_y) return false;
  if(rk[rt_x] > rk[rt_y]) {
	rt[rt_y] = rt_x;
  } else if(rk[rt_x] < rk[rt_y]) {
	rt[rt_x] = rt_y;
  } else {
	rt[rt_x] = rt_y;
	rk[rt_y]++;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  init_ds();
  int res = 0;
  for(int i = 0; i < m; i++) {
	int x, y;
	cin >> x >> y;
	if(!uni(x, y)) {
	  res = i + 1;
	  break;
	}
  }
  
  cout << res << "\n";
  return 0;
}
