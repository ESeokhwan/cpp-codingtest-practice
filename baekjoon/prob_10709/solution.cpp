#include <bits/stdc++.h>
using namespace std;

int h, w;
bool c_info[105][105];
int result[105][105];

char c_input;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> h >> w;
  
  for(int i = 0; i < h; i++) {
	for(int j = 0; j < w; j++) {
	  result[i][j] = -1;
	  cin >> c_input;
	  if(c_input == 'c') c_info[i][j] = true;
	  else c_info[i][j] = false;
	}
  }

  for(int i = 0; i < h; i++) {
	for(int j = 0; j < w; j++) {
	  if(!c_info[i][j]) continue;

	  for(int k = j; k < w; k++) {
		result[i][k] = k - j;
	  }
	}
  }

  for(int i = 0; i < h; i++) {
	for(int j = 0; j < w; j++) {
	  cout << result[i][j]  << " ";
	}
	cout << "\n";
  }
  cout << "\n";
  return 0;
}

