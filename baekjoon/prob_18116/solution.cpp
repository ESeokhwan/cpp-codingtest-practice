#include <bits/stdc++.h>
using namespace std;

int n;

int rt[1000000];
int rk[1000000];
int ln[1000000];

void ds_init() {
  for(int i = 0; i < 1000000; i++) {
	rt[i] = i;
	rk[i] = 0;
	ln[i] = 1;
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
	ln[rt_x] = ln[rt_x] + ln[rt_y];
  } else if(rk[rt_x] < rk[rt_y]) {
	rt[rt_x] = rt_y;
	ln[rt_y] = ln[rt_x] + ln[rt_y];
  } else {
	rt[rt_y] = rt_x;
	ln[rt_x] = ln[rt_x] + ln[rt_y];
	rk[rt_x] += 1;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  ds_init();
  for(int i = 0; i < n; i++) {
	char c;
	cin >> c;
	if(c == 'I') {
	  int input[2];
	  cin >> input[0] >> input[1];
	  ds_union(input[0] - 1, input[1] - 1);
	}
	if(c == 'Q') {
	  int input;
	  cin >> input;
	  cout << ln[ds_find(input - 1)] << "\n";
	}
  }
  return 0;
}
