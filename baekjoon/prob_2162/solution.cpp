#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll nums[3000][4];

int rt[3000];
int rk[3000];
int sz[3000];
int union_cnt;

void ds_init() {
  union_cnt = n;
  for(int i = 0; i < n; i++) {
	rt[i] = i;
	rk[i] = 0;
	sz[i] = 1;
  }
}

int ds_find(int x) {
  if(rt[x] == x) return x;
  return rt[x] = ds_find(rt[x]);
}

bool ds_union(int x, int y) {
  int rtx = ds_find(x);
  int rty = ds_find(y);
  if(rtx == rty) return false;

  union_cnt -= 1;
  if(rk[rtx] > rk[rty]) {
	rt[rty] = rtx;
	sz[rtx] += sz[rty];
  } else if(rk[rtx] == rk[rty]) {
	rt[rty] = rtx;
	sz[rtx] += sz[rty];
	rk[rtx] += 1;
  } else {
	rt[rtx] = rty;
	sz[rty] += sz[rtx];
  }
  return true;
}

ll calc(ll x1, ll y1, ll x2, ll y2, ll x, ll y) {
  return (y2 - y1) * (x - x1) - (x2 - x1) * (y - y1);
}

bool check(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
  ll res1 = calc(x1, y1, x2, y2, x3, y3);
  ll res2 = calc(x1, y1, x2, y2, x4, y4);
  bool isOnOtherSide1 = (res1 * res2 <= 0);

  ll res3 = calc(x3, y3, x4, y4, x1, y1);
  ll res4 = calc(x3, y3, x4, y4, x2, y2);
  bool isOnOtherSide2 = (res3 * res4 <= 0);

  if(res3 == 0 && res4 == 0 && res1 == 0 && res2 == 0) {
	ll max_x1 = max(x1, x2);
	ll min_x1 = min(x1, x2);
	ll max_x2 = max(x3, x4);
	ll min_x2 = min(x3, x4);
	return (max_x1 > min_x2 && max_x2 > min_x1);
  }

  return isOnOtherSide1 && isOnOtherSide2;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> nums[i][0] >> nums[i][1] >> nums[i][2] >> nums[i][3];
  ds_init();

  for(int i = 0; i < n; i++) {
	for(int j = i + 1; j < n; j++) {
	  if(check(
			nums[i][0], nums[i][1], nums[i][2], nums[i][3], 
			nums[j][0], nums[j][1], nums[j][2], nums[j][3]
	  )) {
		ds_union(i, j);
	  }
	}
  }
  int max_sz = 0;
  for(int i = 0; i < n; i++) max_sz = max(max_sz, sz[i]);

  cout << union_cnt << "\n";
  cout << max_sz << "\n";
  return 0;
}
