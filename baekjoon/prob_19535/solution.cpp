#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int n;
vector<int> edges[300000];
int visited[300000];

ll calc_D_1(int st) {
  ll res = 0;

  for (int edge: edges[st]) {
	res += ((edges[edge].size() - 1) * (edges[st].size() - 1));
  }
  return res;
}

ll calc_D() {
  ll res = 0;
  for (int i = 0; i < n; i++) {
	res += calc_D_1(i);
  }
  return res / 2;
}

ll calc_G() {
  ll res = 0;
  for (int i = 0; i < n; i++) {
	ll s = edges[i].size();
	if (s >= 3) {
	  res += (ll) ((s * (s - 1) * (s - 2)) / 6);
	}
  }
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
	int input1, input2;
	cin >> input1 >> input2;
	edges[input1 - 1].push_back(input2 - 1);
	edges[input2 - 1].push_back(input1 - 1);
  }

  memset(visited, 0, sizeof(visited));
  ll d_cnt = calc_D();
  ll g_cnt = calc_G();

  if (d_cnt > 3 * g_cnt) cout << "D\n";
  else if (d_cnt < 3 * g_cnt) cout << "G\n";
  else cout << "DUDUDUNGA\n";
  return 0;
}
