#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[5000][2];

int rt[1000000];
int rk[1000000];

void ds_init() {
  memset(rk, 0, sizeof(rk));
  for(int i = 0; i < 1000000; i++) {
    rt[i] = i;
  }
}

int ds_find(int x) {
  if(rt[x] == x) return x;
  return (rt[x] = ds_find(rt[x]));
}

bool ds_union(int x, int y) {
  int rtx = ds_find(x);
  int rty = ds_find(y);
  if(rtx == rty) return false;
  if(rk[rtx] > rk[rty]) {
	rt[rty] = rtx;
  } else if(rk[rty] > rk[rtx]) {
    rt[rtx] = rty;
  } else {
    rk[rty] += 1;
    rt[rtx] = rty;
  }
  return true;
}

void f(int st, int en) {
  if(st >= en) return;
  if(ds_find(st) == ds_find(en)) return;
  f(st, (st + en) / 2);
  f((st + en) / 2 + 1, en);
  ds_union(st, en);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ds_init();
    
  cin >> n >> m;
  for(int i = 0; i < m; i++) cin >> input[i][0] >> input[i][1];
  for(int i = 0; i < m; i++) f(input[i][0] - 1, input[i][1] - 1);

  int res = 0;
  for(int i = 0; i < n; i++) {
	if(i == ds_find(i)) res += 1;
  }
  cout << res << "\n";
  return 0;
}
