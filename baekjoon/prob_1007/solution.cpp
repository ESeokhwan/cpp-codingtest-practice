#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n;
ll ps[20][2];
double res;

void dfs(ll acc_x, ll acc_y, int idx, int cnt) {
  if(idx == n) {
	if(res == -1.0) res = sqrt((double) (acc_x * acc_x + acc_y * acc_y));
	else res = min(res, sqrt((double) (acc_x * acc_x + acc_y * acc_y)));
	return;
  }
  if(cnt == (n / 2)) {
	dfs(acc_x - ps[idx][0], acc_y - ps[idx][1], idx + 1, cnt);
	return;
  }
  if(n - idx <= (n / 2) - cnt) {
	dfs(acc_x + ps[idx][0], acc_y + ps[idx][1], idx + 1, cnt + 1);
	return;
  }
  dfs(acc_x + ps[idx][0], acc_y + ps[idx][1], idx + 1, cnt + 1);
  dfs(acc_x - ps[idx][0], acc_y - ps[idx][1], idx + 1, cnt);
}

void solution() {
  res = -1.0;

  cin >> n;
  for(int i = 0; i < n; i++) {
	cin >> ps[i][0] >> ps[i][1];
  }
  dfs(0, 0, 0, 0);

  printf("%.6f\n", res);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  for(int i = 0; i < t; i++) {
	solution();
  }
  cout << "\n";
  return 0;
}
