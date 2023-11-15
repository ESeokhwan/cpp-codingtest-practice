#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> gas_s[10000];
int l;
int p;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> gas_s[i].first >> gas_s[i].second;
  cin >> l >> p;
  sort(gas_s, gas_s + n);

  priority_queue<int> pq;
  int cnt = 0;
  int cur_gas = p;
  for(int i = 0; i < n; i++) {
	while(cur_gas < gas_s[i].first) {
	  if(pq.empty()) {
		cout << -1 << "\n";
		return 0;
	  }
	  cnt += 1;
	  cur_gas += pq.top();
	  pq.pop();
	}
	pq.push(gas_s[i].second);
  }
  
  while(cur_gas < l) {
	if(pq.empty()) {
	  cout << -1 << "\n";
	  return 0;
	}
	cnt += 1;
	cur_gas += pq.top();
	pq.pop();
  }

  cout << cnt << "\n";
  return 0;
}
