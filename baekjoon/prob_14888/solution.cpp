#include <bits/stdc++.h>
using namespace std;

int n, min_res, max_res;
int nums[11];
int opers[10];

int oper_cnt[4];

int calc() {
  int res = nums[0];
  for (int i = 0; i < n - 1; i++) {
	if (opers[i] == 0) {
	  res += nums[i + 1];
	} else if(opers[i] == 1) {
	  res -= nums[i + 1];
	} else if(opers[i] == 2) {
	  res *= nums[i + 1];
	} else if(opers[i] == 3) {
	  res /= nums[i + 1];
	}
  }
  return res;
}

void bf(int cnt) {
  if (cnt == n - 1) {
	int tmp_res = calc();
	max_res = max(max_res, tmp_res);
	min_res = min(min_res, tmp_res);
	return;
  }
  for (int i = 0; i < 4; i++) {
	if (oper_cnt[i] == 0) continue;
	opers[cnt] = i;
	oper_cnt[i] -= 1;
	bf(cnt + 1);
	oper_cnt[i] += 1;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
	cin >> nums[i];
  }
  for (int i = 0; i < 4; i++) {
	cin >> oper_cnt[i];
  }

  max_res = -2000000100;
  min_res = 2000000100;
  bf(0);

  cout << max_res << "\n";
  cout << min_res << "\n";
  return 0;
}
