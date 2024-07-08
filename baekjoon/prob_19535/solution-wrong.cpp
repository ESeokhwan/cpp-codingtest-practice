#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int n;
int parent[300005];
ll indeg[300005];

ll calc_D() {
  ll res = 0;
  for (int i = 0; i < n; i++) {
	int cnt = 1;
	int cur = i;
	while (cur != -1) {
	  if (cnt == 4) {
		res += 1;
		break;
	  }
	  if (cnt == 3) {
		res += (indeg[cur] - 1);
	  }
	  cur = parent[cur];
	  cnt += 1;
	}	  
  }
  return res;
}

ll calc_J() {
  ll res = 0;
  for (int i = 0; i < n; i++) {
	ll s = indeg[i];
	if (s >= 3) {
	  res += (ll) ((s * (s - 1) * (s - 2)) / 6);
	} 
	if (s >= 2 && parent[i] != -1) {
	  res += (ll) ((s * (s - 1)) / 2);
	}
  }
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(indeg, 0, sizeof(indeg));
  memset(parent, -1, sizeof(parent));
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
	int input1, input2;
	cin >> input1 >> input2;
	if (parent[input2 - 1] == -1) {
	  parent[input2 - 1] = input1 - 1;
	  indeg[input1 - 1] += 1;
	} else {
	  parent[input1 - 1] = input2 - 1;
	  indeg[input2 - 1] += 1;
	}
  }

  ll d_cnt = calc_D();
  ll j_cnt = calc_J();

  if (d_cnt > 3 * j_cnt) cout << "D\n";
  else if (d_cnt < 3 * j_cnt) cout << "G\n";
  else cout << "DUDUDUNGA\n";
  return 0;
}
