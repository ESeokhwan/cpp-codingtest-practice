#include <bits/stdc++.h>
using namespace std;

int n, k;

bool check(int num) {
  int cnt = 0;
  for(int i = 1; i <= n; i++) {
	cnt += min(n, (num / i));
  }
  if(cnt < k) return false;
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  int st = 1;
  int en = 1000000000;
  while(st < en) {
	int mid = (st + en) / 2;
	if(check(mid)) {
	  st = st;
	  en = mid;
	} else {
	  st = mid + 1;
	  en = en;
	}
  }

  cout << st << "\n";
  return 0;
}
