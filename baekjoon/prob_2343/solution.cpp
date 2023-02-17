#include<bits/stdc++.h>

using namespace std;

int N, M;

int lec[100000];

int div_and_ceiling(int n, int divider) {
  if(n % divider == 0) return n / divider;
  else return (n / divider) + 1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int lec_sum = 0;
  int longest_lec = 0;

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
	cin >> lec[i];
	lec_sum += lec[i];
	longest_lec = max(longest_lec, lec[i]);
  }

  int res;
  int basis = div_and_ceiling(lec_sum, M);
  int sp = max(basis, longest_lec);
  for(int expected = basis; true; expected++) {
	int local_sum = 0;
	int blue_cnt = 1;
	bool fail = false;
	for(int i = 0; i < N; i++) {
	  if(lec[i] > expected) {
		fail = true;
		break;
	  }
	  if(local_sum + lec[i] <= expected) {
		local_sum += lec[i];
	  } else {
		blue_cnt++;
		if(blue_cnt > M) {
		  fail=true;
		  break;
		}
		local_sum = lec[i];
	  }
	}
	if(!fail) {
	  res = expected;
	  break;
	}
  }

  cout << res << "\n";
  cout << "\n";
  return 0;
}
