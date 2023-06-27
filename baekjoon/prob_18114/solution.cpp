#include <bits/stdc++.h>
using namespace std;

int n, c;
int w[5000];

int check() {
  for(int i = 0; i < n; i++) {
	if(w[i] == c) return 1;
  }

  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  if(i == j) continue;
	  int rem = c  - (w[i] + w[j]);
	  if(rem == 0) return 1;
	  int idx = lower_bound(w, w + n, rem) - w;
	  if(i == idx || j == idx) continue;
	  if(w[idx] == rem) return 1;
	}
  }
  return 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> c;
  for(int i = 0; i < n; i++) cin >> w[i];
  sort(w, w + n);

  cout << check() << "\n";
  return 0;
}
