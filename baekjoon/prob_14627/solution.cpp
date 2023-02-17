#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int S, C;
ll pa[1000000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> S >> C;
  for(int i = 0; i < S; i++) cin >> pa[i];

  ll st = 1;
  ll en = 1000000000L;
  while(st < en) {
	ll mid = ((st + en) / 2) + 1;
	ll dak_cnt = 0;
	for(int i = 0; i < S; i++) {
	  dak_cnt += (pa[i] / mid);
	}

	if(dak_cnt < C) {
	  en = mid - 1;
	}
	else {
	  st = mid;
	}
  }
  
  ll total_pa = 0;
  for(int i = 0; i < S; i++) {
	total_pa += pa[i];
  }

  cout << total_pa - (C * st) << "\n";
  cout << "\n";
  return 0;
}
