#include <bits/stdc++.h>
using namespace std;

int n, m, l;
int shoot_p[100000];
int animals[100000][2];


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> l;
  for (int i = 0; i < n; i++) {
	cin >> shoot_p[i];
  }
  for (int i = 0; i < m; i++) {
	cin >> animals[i][0] >> animals[i][1];
  }

  int cnt = 0;
  sort(shoot_p, shoot_p + n);
  for (int i = 0; i < m; i++) {
	if (l < animals[i][1]) continue;
	int st = max(0, animals[i][0] - (l - animals[i][1]));
	int en = min(1000000000, animals[i][0] + (l - animals[i][1]));
	
	int target_idx = (lower_bound(shoot_p, shoot_p + n, st) - shoot_p);
	if (target_idx == n || shoot_p[target_idx] > en) continue;
	cnt += 1;
  }

  cout << cnt << "\n";
  return 0;
}
