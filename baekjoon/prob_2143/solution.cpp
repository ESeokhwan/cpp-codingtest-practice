#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, m, n;
int a[1000];
int b[1000];
ll dp_a[1000][1000];
ll dp_b[1000][1000];
vector<ll> b_l;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for(int i = 0; i < m; i++) cin >> b[i];

  for(int i = 0; i < n; i++) {
	dp_a[i][i] = a[i];
	for(int j = i + 1; j < n; j++) dp_a[i][j] = dp_a[i][j-1] + a[j];
  }
  
  for(int i = 0; i < m; i++) {
	dp_b[i][i] = b[i];
	b_l.push_back(dp_b[i][i]);
	for(int j = i + 1; j < m; j++) {
	  dp_b[i][j] = dp_b[i][j-1] + b[j];
	  b_l.push_back(dp_b[i][j]);
	}
  }
  sort(b_l.begin(), b_l.end());

  ll res = 0;
  for(int i = 0; i < n; i++) {
	for(int j = i; j < n; j++) {
	  ll rem = ((ll) t) - dp_a[i][j];
	  int tmp = (upper_bound(b_l.begin(), b_l.end(), rem) - lower_bound(b_l.begin(), b_l.end(), rem));
	  res += tmp;
	}
  }

  cout << res;
  cout << "\n";
  return 0;
}
