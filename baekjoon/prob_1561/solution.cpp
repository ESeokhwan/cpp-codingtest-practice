#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long gi[10000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < m; i++) cin >> gi[i];

  long long st, en, mid;
  st = 0;
  en = n * 30;
  while(st < en) {
	mid = (st + en) / 2;

	long long tmp_res = 0;
	for(int i = 0; i < m; i++) tmp_res += (1 + (mid / gi[i]));
	
	if(tmp_res >= n) en = mid;
	else st = mid + 1;
  }

  int res = 0;
  long long cnt = 0;
  if(st != 0) {
	for(int i = 0; i < m; i++) {
	  cnt += ((st - 1) / gi[i] + 1);
	}
  }

  for(int i = 0; i < m; i++) {
	if(en % gi[i] == 0) cnt += 1;
	if(cnt == n) {
	  res = i + 1;
	  break;
	}
  }

  cout << res << "\n";
  return 0;
}
