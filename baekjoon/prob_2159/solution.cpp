#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
pair<ll, ll > sp;
pair<ll, ll > cus[100000][5];

ll dp[100000][5];

pair<ll, ll> dirs[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

ll calc_dist(pair<ll, ll> st, pair<ll, ll> en) {
  ll x_dist = st.first - en.first;
  if(x_dist < 0) x_dist = -1 * x_dist;
  
  ll y_dist = st.second - en.second;
  if(y_dist < 0) y_dist = -1 * y_dist;

  return x_dist + y_dist;
}

ll mwom(ll a, ll b) {
  if(a < 0) return b;
  return min(a, b);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  cin >> sp.first >> sp.second;
  for(ll i = 0; i < n; i++) {
	cin >> cus[i][0].first >> cus[i][0].second;
	for(ll j = 0; j < 4; j++) {
	  cus[i][1 + j].first = cus[i][0].first + dirs[j].first;
	  cus[i][1 + j].second = cus[i][0].second + dirs[j].second;
	}
  }

  memset(dp, -1, sizeof(dp));
  for(ll i = 0; i < 5; i++) {
	dp[0][i] = calc_dist(cus[0][i], sp);
  }

  for(ll i = 1; i < n; i++) {
	for(ll j = 0; j < 5; j++) {
	  for(ll k = 0; k < 5; k++) {
		dp[i][j] = mwom(dp[i][j], dp[i - 1][k] + calc_dist(cus[i][j], cus[i-1][k]));
	  }
	}
  }

  ll res = -1;
  for(ll i = 0; i < 5; i++) res = mwom(res, dp[n - 1][i]);
  cout << res << "\n";
  return 0;
}
