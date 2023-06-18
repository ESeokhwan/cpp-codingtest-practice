#include <bits/stdc++.h>
using namespace std;

int n;
int lc[100000];
int rc[100000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cnt = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
	int input[3];
	cin >> input[0] >> input[1] >> input[2];
	lc[input[0] - 1] = input[1] - 1;
	rc[input[0] - 1] = input[2] - 1;
	if(input[1] > 0) cnt += 1;
	if(input[2] > 0) cnt += 1;
  }

  int cur = 0;
  int height = 0;
  while(rc[cur] >= 0) {
	height += 1;
	cur = rc[cur];
  }

  cout << 2 * cnt - height << "\n";
  return 0;
}
