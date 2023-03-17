#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m, k;
ll init_nums[1000000];
ll input[20000][3];

ll nums[1000000];
ll accs[25];

ll get_sum(int a) {
  if(a < 0) return 0;
  ll res = nums[a];
  int tmp = a + 1;
  int div = 0;
  while(tmp >> div != 0) {
	if(tmp == (tmp >> div) << div) {
	  div++;
	  continue;
	}
	tmp = (tmp >> div) << div;
	res += nums[tmp - 1];
	div++;
  }
  return res;
}

ll get_sum(int a, int b) {
  return get_sum(b) - get_sum(a - 1);
}

void update(int idx, ll val) {
  ll old_val = get_sum(idx, idx);
  int tmp = idx + 1;
  while(tmp <= n) {
	nums[tmp - 1] += (val - old_val);
	tmp += (tmp & -tmp);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 0; i < 25; i++) accs[i] = 0;

  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) cin >> init_nums[i];
  for(int i = 0; i < m + k; i++) cin >> input[i][0] >> input[i][1] >> input[i][2];

  for(int i = 0; i < n; i++) {
	ll tar = init_nums[i];
	int tmp1 = n;
	int tmp2 = i + 1;
	int cnt1 = 0;
	int cnt2 = 0;
	while(tmp1 != 0) {
	  tmp1 = tmp1 >> 1;
	  accs[cnt1] += tar;
	  cnt1++;
	  if(tmp2 % 2 == 0) {
		tmp2 = tmp2 >> 1;
		accs[cnt2] = 0;
		cnt2 = cnt1;
	  }
	}
	nums[i] = accs[cnt2];
  }

  for(int i = 0; i < m + k; i++) {
	if(input[i][0] == 1) update(input[i][1] - 1, input[i][2]);
	if(input[i][0] == 2) cout << get_sum(input[i][1] - 1, input[i][2] - 1) << "\n";
  }
  return 0;
}
