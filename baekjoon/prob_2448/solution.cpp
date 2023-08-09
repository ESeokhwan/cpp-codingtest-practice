#include <bits/stdc++.h>
using namespace std;

int n;

int pic[6500][6500];

void make_tri(int size, int r, int c) {
  if(size == 3) {
	pic[r][c] = 1;
	pic[r + 1][c - 1] = 1;
	pic[r + 1][c + 1] = 1;
	for(int i = -2; i <= 2; i++) pic[r + 2][c + i] = 1;
	return;
  }
  int offset = size / 2;
  make_tri(size / 2, r, c);
  make_tri(size / 2, r + offset, c + offset);
  make_tri(size / 2, r + offset, c - offset);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(pic, 0, sizeof(pic));
  cin >> n;

  make_tri(n, 0, n - 1);
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < 2*n; j++) {
	  if(pic[i][j] == 1) cout << "*";
	  else cout << " ";
	  }
	cout << "\n";
  }
  return 0;
}
