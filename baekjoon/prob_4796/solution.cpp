#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, p, v;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int idx = 1;
  while (true) {
	cin >> l >> p >> v;
	if (l == 0 && p == 0 && v == 0) break;
	ll res = l * (v / p) + min(l, v % p);
	cout << "Case " << idx << ": " << res << "\n";
	idx += 1;
  }
  cout << "\n";
  return 0;
}
