#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll  n, k;
ll pos[100000];
priority_queue<ll, vector<ll>, greater<ll> > pq;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> pos[i];
  sort(pos, pos + n);

  pq.push(100000);
  for(int i = 0; i < n - 1; i++) {
	ll cur_right = (pos[i + 1] - pos[i] - 1) / 2;
	ll next_left = (pos[i + 1] - pos[i] - 1) - cur_right;
	pq.push(cur_right);
	pq.push(next_left);
  }
  pq.push(100000);

  ll tmp = 0;
  ll res = 0;
  ll cnt = 2 * n;
  while(true) {
	ll cur = pq.top();
	if(k - (cur - tmp) * cnt <= 0) break;
	pq.pop();
	k -= (cur - tmp) * cnt;
	res += cnt * ((cur + tmp + 1) * (cur - tmp)) / 2;
	cnt -= 1;
	tmp = cur;
  }

  for(int i = 0; i < k; i++) {
	if(i%cnt == 0) tmp += 1;
	res += tmp;
  }
  cout << res << "\n";
  return 0;
}
