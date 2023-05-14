#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int wish[100000];
int idxes[100000];

void solution() {
  cin >> n;
  for(int i = 0; i < n; i++) {
	cin >> wish[i];
	wish[i] = wish[i] - 1;
  }

  int res = n;
  memset(idxes, 0, sizeof(idxes));
  for(int i = 0; i < n; i++) {
	if(idxes[i] != 0) continue;
	
	int cur = i;
	int cnt = 0;
	while(idxes[cur] == 0) {
	  idxes[cur] = ++cnt;
	  cur = wish[cur];
	}
	if(idxes[cur] != -1) res -= (cnt - idxes[cur] + 1);
	
	cur = i;
	while(idxes[cur] != -1) {
	  idxes[cur] = -1;
	  cur = wish[cur];
	}
  }

  cout << res << "\n";
  return;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  for(int i = 0; i < t; i++) solution();
  return 0;
}
