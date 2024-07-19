#include "bits/stdc++.h"
using namespace std;

int n;
int m;
int prices[10];

vector<int> dfs(int budget, vector<int> acc, int cnt) {
//  cout << "budget: " << budget << " cnt: " << cnt << " acc.first: " << acc.first << "\n";
//  cout << "acc.second: ";
//  for (int x: acc.second) {
//	cout << x;
//  }
//  cout << "\n";
  if (cnt == 0) return acc;

  for (int i = n - 1; i >= 0; i--) {
	vector<int> new_acc;
	new_acc = acc;
	new_acc.push_back(i);
	if (budget < prices[i]) continue;
	vector<int> tmp_res = dfs(budget - prices[i], new_acc, cnt - 1);
	if (tmp_res.size() != 0) return tmp_res;
  }
  return {};
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n;
  for (int i = 0; i < n; i++) {
	cin >> prices[i];
  }
  cin >> m;

  for (int i = 50; i >= 1; i--) {
	vector<int> res = dfs(m, {}, i);
	if (res.size() != 0 && res[0] != 0) {
	  for (int j = 0; j < res.size(); j++) {
		cout << res[j];
	  }
	  cout << "\n";
	  return 0;
	}
  }

  cout << "0\n";
  return 0;
}

