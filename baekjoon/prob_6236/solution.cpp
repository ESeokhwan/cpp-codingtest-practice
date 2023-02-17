#include <bits/stdc++.h>
using namespace std;

int N, M;
int schedule[100000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
	cin >> schedule[i];
  }

  int st = 1;
  int en = 1000000000;
  while(st < en) {
	int ex = (st + en) / 2;

	int cur_bud = 0;
	int w_count = 0;
	bool fail = false;
	for(int i = 0; i < N; i++) {
	  if(cur_bud < schedule[i]) {
		cur_bud = ex;
		w_count += 1;
		if(w_count > M) {
		  fail = true;
		  break;
		}
	  }

	  cur_bud -= schedule[i];
	  if(cur_bud < 0) {
		fail = true;
		break;
	  }
	}

	if(fail) st = ex+1;
	else en = ex;
  }

  cout << en << "\n";
  cout << "\n";
  return 0;
}
