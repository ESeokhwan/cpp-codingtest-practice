#include <bits/stdc++.h>
using namespace std;

int n;
double m;

int cals[5000];
double prices[5000];

int solutions[20005];

int ptoi(double p) {
  return (int)(p * 100 + 0.5);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while(true) {
	memset(solutions, 0, sizeof(solutions));
	cin >> n >> m;
	if(n == 0 && m == 0.00) break;
	
	for(int i = 0; i < n; i++) cin >> cals[i] >> prices[i];

	int m_int = ptoi(m);
    for(int i = 0; i < n; i++) {
	  for(int j = ptoi(prices[i]); j <= m_int; j++) {
		solutions[j] = max(solutions[j], cals[i]);
	  }
	}

	sort(prices, prices+n);
	for(int i = 0; i <= n; i++) {
	  int idx = ptoi(prices[i]);
	  for(int j = 0; j <= (m_int - idx); j++) {
		if(solutions[idx] == 0 || solutions[j] == 0) continue;
		solutions[idx+j] = max(solutions[idx+j], solutions[idx]+solutions[j]);
	  }
	}

	int max_cal = 0;
	for(int i = 1; i <= m_int; i++) {
	  max_cal = max(max_cal, solutions[i]);
	  solutions[i] = max_cal;
	}
	cout << solutions[ptoi(m)] << "\n";
  }

  cout << "\n";
  return 0;
}
