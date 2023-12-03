#include <bits/stdc++.h>
using namespace std;

int n, m;
int chues[30];
int balls[7];

bool possible_diffs[31][15001];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> chues[i];
  cin >> m;
  for(int i = 0; i < m; i++) cin >> balls[i];

  memset(possible_diffs, false, sizeof(possible_diffs));
  possible_diffs[0][0] = true;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j <= i * 500; j++) {
	  if(!possible_diffs[i][j]) continue;
	  possible_diffs[i + 1][j] = true;
	  possible_diffs[i + 1][j + chues[i]] = true;
	  if(j - chues[i] < 0) possible_diffs[i + 1][chues[i] - j] = true;
	  else possible_diffs[i + 1][j - chues[i]] = true;
	}
  }

  for(int i = 0; i < m; i++) {
	bool can_make = false;
	if(balls[i] <= 15000) {
	  for(int j = 0; j < n + 1; j++) {
	    if(possible_diffs[j][balls[i]]) {
		  can_make = true;
		  break;
	    }
	  }
	}
	if(can_make) {
	  cout << "Y" << " ";
	} else {
	  cout << "N" << " ";
	}
  }
  cout << "\n";
  return 0;
}
