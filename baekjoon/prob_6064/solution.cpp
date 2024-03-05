#include <bits/stdc++.h>
using namespace std;

int t;
int M, N, x, y;
int answer;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> t;
  for(int i = 0; i < t; i++) {
	answer = -1;
	cin >> M >> N >> x >> y;
	for (int j = 0; j < N; j++) {
	  int yTimes = M * j + x - y;
	  if (yTimes < 0 || yTimes % N != 0) continue;
	  answer = M * j + x;
	  break;
	}
	cout << answer << "\n";
  }

  cout << "\n";
  return 0;
}
