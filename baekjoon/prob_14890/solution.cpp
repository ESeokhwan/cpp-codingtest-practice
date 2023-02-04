#include <bits/stdc++.h>
using namespace std;

int N, L;

int h[100][100][2];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> L;

  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  int input;
	  cin >> input;
	  h[i][j][0] = input;
	  h[j][i][1] = input;
	}
  }

  int cnt = 0;

  bool can_pass;
  int prev;
  int prev_suc;
  int next_suc;
  for(int k = 0; k < 2; k++) {
	for(int i = 0; i < N; i++) {
	  can_pass = true;
	  prev = 0;
	  prev_suc = 0;
	  next_suc = 0;
	  for(int j = 0; j < N; j++) {
		int cur = h[i][j][k];
		if(prev == 0) {
		  prev_suc++;
		  prev = cur;
		} else if(prev == cur) {
		  if(next_suc > 0) next_suc--;
		  else prev_suc++;
		  prev = cur;
		} else if(cur == prev+1) {
		  if(prev_suc < L || next_suc > 0) {
			can_pass = false;
			break;
		  }
		  prev_suc = 1;
		  prev = cur;
		} else if(cur == prev-1) {
		  if(next_suc > 0) {
			can_pass = false;
			break;
		  }
		  prev_suc = 0;
		  next_suc = L-1;
		  prev = cur;
		} else {
		  can_pass = false;
		  break;
		}
	  }
	  if(can_pass && next_suc == 0) {
		cnt++;
	  }
	}
  }

  cout << cnt << "\n";
  cout << "\n";
  return 0;
}
