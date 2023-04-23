#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int d;
ll dp[8][8];
ll mod = 1000000007;

ll acc_dp[8][8] = {
  {1, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 1}
};

ll init[8][8] = {
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 0, 0},
  {0, 1, 1, 0, 1, 1, 0, 0},
  {0, 0, 1, 1, 0, 1, 1, 0},
  {0, 0, 0, 1, 1, 0, 0, 1},
  {0, 0, 0, 0, 1, 0, 0, 1},
  {0, 0, 0, 0, 0, 1, 1, 0}
};

ll add(ll a, ll b) {
  return (a + b) % mod;
}

ll mult(ll a, ll b) {
  return ((a % mod) * (b % mod)) % mod;
}

void double_up() {
  ll tmp[8][8];
  for(int i = 0; i < 8; i++) {
	for(int j = 0; j < 8; j++) {
	  tmp[i][j] = 0;
	  for(int k = 0; k < 8; k++) {
		tmp[i][j] = add(tmp[i][j], mult(dp[i][k], dp[k][j]));
	  }
	}
  }

  for(int i = 0; i < 8; i++) {
	for(int j = 0; j < 8; j++) dp[i][j] = tmp[i][j];
  }
}

void add_up() {
  ll tmp[8][8];
  memset(tmp, 0, sizeof(tmp));
  for(int i = 0; i < 8; i++) {
	for(int j = 0; j < 8; j++) {
	  for(int k = 0; k < 8; k++) {
		tmp[i][j] = add(tmp[i][j], mult(dp[i][k], init[k][j]));
	  }
	}
  }

  for(int i = 0; i < 8; i++) {
	for(int j = 0; j < 8; j++) dp[i][j] = tmp[i][j];
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 0; i < 8; i++) {
	for(int j = 0; j < 8; j++) {
	  dp[i][j] = init[i][j];
	}
  }

  cin >> d;
  int cnt;
  while(d > 0) {
	for(cnt = 2; cnt <= d; cnt *= 2) {
	  double_up();
	}

	ll tmp[8][8];
	for(int i = 0; i < 8; i++) {
	  for(int j = 0; j < 8; j++) {
	    tmp[i][j] = 0;
		for(int k = 0; k < 8; k++) {
		  tmp[i][j] = add(tmp[i][j], mult(acc_dp[i][k], dp[k][j]));
		}
	  }
	}
	for(int i = 0; i < 8; i++) {
	  for(int j = 0; j < 8; j++) {
		acc_dp[i][j] = tmp[i][j];
		dp[i][j] = init[i][j];
	  }
	}
	d = d % (cnt / 2);
  }

  cout << acc_dp[0][0] <<"\n";
  return 0;
}
