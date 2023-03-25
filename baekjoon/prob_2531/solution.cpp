#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;

int st;
int sushi[30000];
bool is_in[3001];
int dp[30000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> d >> k >> c;

  for(int i = 0; i < n; i++) cin >> sushi[i];
  
  for(int i = 0; i < n; i++) {
	int tmp = 1;
	memset(is_in, 0, sizeof(is_in));
	is_in[c] = true;
	for(int j = 0; j < k; j++) {
	  if(!is_in[sushi[(i + j) % n]]) {
		tmp++;
		is_in[sushi[(i + j) % n]] = true;
	  }
	}
	dp[i] = tmp;
  }

  int res = 0;
  for(int i = 0; i < n; i++) res = max(res, dp[i]);
  
  cout << res << "\n";
  return 0;
}

