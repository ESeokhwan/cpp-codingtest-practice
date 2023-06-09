#include<bits/stdc++.h>

using namespace std;

int N, M;

int lec[100000];

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

  int st = 1;
  int en = 1000000000;
  while(st < en) {
	int expected = (st + en)/2;
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
	if(fail) {
	  st = expected + 1;
	}
	if(!fail) {
	  en = expected;
	}
  }

  cout << en << "\n";
  cout << "\n";
  return 0;
}
