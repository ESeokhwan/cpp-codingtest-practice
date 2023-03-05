#include <bits/stdc++.h>
using namespace std;

string input;

bool is_pel[2500][2500];
int pel_cnt[2500];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(pel_cnt, -1, sizeof(pel_cnt));
  cin >> input;

  int str_len = input.length();
  for(int i = 0; i < str_len; i++) {
	is_pel[i][i] = true;
	if(i != 0) is_pel[i-1][i] = (input[i-1] == input[i]);
  }
  
  for(int i = 1; i < str_len; i++) {
	for(int j = i-2; j >= 0; j--) {
	  is_pel[j][i] = (is_pel[j+1][i-1] && input[j] == input[i]);
	}
  }
  
  pel_cnt[0] = 1;
  for(int i = 1; i < str_len; i++) {
	pel_cnt[i] = i + 1;
	for(int j = i; j >= 0; j--) {
	  if(is_pel[j][i]) pel_cnt[i] = min(pel_cnt[i], pel_cnt[j-1] + 1);
	}
  }

  cout << pel_cnt[str_len-1] << "\n";
  return 0;
}
