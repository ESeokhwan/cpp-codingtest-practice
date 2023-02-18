#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, y;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);  

  cin >> x >> y;

  ll prev_wr = (y * 100L) / x;

  ll st = 1L;
  ll en = 1000000000L;
  while(st < en) {
	ll mid = (st + en) / 2L;
	ll cur_wr = ((y+mid) * 100L) / (x+mid);
	
	if(cur_wr > prev_wr) en = mid;
	else st = mid + 1L;
  }

  if(prev_wr >= 99) st = -1L;
  cout << st << "\n";
  cout << "\n";
  return 0;
}

