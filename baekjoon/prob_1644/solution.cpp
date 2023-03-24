#include <bits/stdc++.h>
using namespace std;

int n;

bool is_prime[4000001];
vector<int> prime;
int dp[4000001];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  memset(is_prime, true, sizeof(is_prime));
  for(int i = 2; i <= n; i++) {
	if(!is_prime[i]) continue;
	for(int j = 2 * i; j <= n; j += i) is_prime[j] = false;
	
	prime.push_back(i);
  }

  if(prime.size() == 0) {
	cout << "0\n";
	return 0;
  }

  int res = 0;
  int st = prime.size() - 1;
  int ln = 0;
  int sum = prime.back();
  if(sum == n) res += 1;

  for(int i = prime.size() - 2; i >= 0; i--) {
	if(i - ln < 0) break;
	sum -= prime[st];
	sum += prime[i - ln];
	st = i;
	if(sum == n) {
	  res += 1;
	  continue;
	}

	while(i - ln - 1 >= 0 && sum + prime[i - ln - 1] <= n) {
	  ln += 1;
	  sum += prime[i - ln];
	  if(sum == n) res += 1;
	}
  }

  cout << res << "\n";
  return 0;
}
