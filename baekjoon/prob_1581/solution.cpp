#include <bits/stdc++.h>
using namespace std;

int mzs[4];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> mzs[0] >> mzs[1] >> mzs[2] >> mzs[3]; // ff fs sf ss

  int res = 0;
  if (mzs[1] > 0) {
	res = mzs[0] + mzs[3];
	if (mzs[1] > mzs[2]) {
	  res += (1 + 2 * mzs[2]);
	} else {
	  res += (2 * mzs[1]);
	}
  } else if(mzs[0] > 0) {
	res = mzs[0];
  } else {
	res = mzs[3];
	if (mzs[2] > 0) {
	  res += 1;
	}
  }

  cout << res  << "\n";
  return 0;
}
