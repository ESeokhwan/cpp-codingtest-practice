#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;
ll muls[10000];

bool isOk(ll a) {
  ll cnt = 0;
  for(ll i = 0; i < n; i++) cnt += (muls[i] / a);
  if(cnt < k) return true;
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for(ll i = 0; i < n; i++) cin >> muls[i];

  ll st = 0L;
  ll en = ((ll) INT_MAX) * 10000L / k;
  ll mid;
  while(st < en) {
	mid = (st + en) / 2L;
	if(isOk(mid)) en = mid;
	else st = mid + 1;
  }

  cout << en - 1<< "\n";
  return 0;
}
