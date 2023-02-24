#include <bits/stdc++.h>
using namespace std;

int n, k;
int coins[100];
int solutions[20005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(solutions, -1, sizeof(solutions));

  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> coins[i];

  for(int i = 0; i < n; i++) {
	if(coins[i] <= k) solutions[coins[i]] = 1;
  }
  
  for(int i = 0; i < k; i++) {
	for(int j = 0; j <= i; j++) {
	  if(solutions[i] == -1 || solutions[j] == -1) continue;
	  if(solutions[i+j] == -1) solutions[i+j] = solutions[i] + solutions[j];
	  solutions[i+j] = min(solutions[i+j], solutions[i] + solutions[j]);
	}
  }

  cout << solutions[k];
  cout << "\n";
  return 0;
}
