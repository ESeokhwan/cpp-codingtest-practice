#include <bits/stdc++.h>
using namespace std;

int n;
int lis[100000];
int res[3];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> lis[i];
  sort(lis, lis+n);

  res[0] = 2000000001;

  for(int i = 0; i < n; i++) {
	int rem = 0 - lis[i];
	int lower = lower_bound(lis, lis+n, rem) - lis;
	if(lower == n) lower = lower - 1;
	else if(lis[lower] != rem) lower = lower - 1;
	if(lower == i) lower = lower - 1;
	
	int upper = upper_bound(lis, lis+n, rem) - lis;
	if(upper == i) upper = upper + 1;

	if(lower >= 0) {
	  if(res[0] > abs(lis[i] + lis[lower])) {
		res[0] = abs(lis[i] + lis[lower]);
		res[1] = i;
		res[2] = lower;
	  }
	}
	if(upper < n) {
	  if(res[0] > abs(lis[i] + lis[upper])) {
		res[0] = abs(lis[i] + lis[upper]);
		res[1] = i;
		res[2] = upper;
	  }
	}
  }

  if(lis[res[1]] > lis[res[2]]) cout << lis[res[2]] << " " << lis[res[1]] << "\n";
  else cout << lis[res[1]] << " " << lis[res[2]] << "\n";
  return 0;
}
