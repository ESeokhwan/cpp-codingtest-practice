#include <bits/stdc++.h>
using namespace std;

int n, k, m;
int dp[1000001][11];
set<int> candidates;

void init_candidates() {
  vector<int> nums;
  int tmp = n;
  while(tmp != 0) {
	nums.push_back(tmp % 10);
	tmp /= 10;
  }
  m = nums.size();
  sort(nums.begin(), nums.end());

  do {
	if(nums[0] == 0) continue;
	int res = 0;
	for (int i = 0; i < m; i++) {
	  res *= 10;
	  res += nums[i];
	}
	candidates.insert(res);
  } while (next_permutation(nums.begin(), nums.end()));
}

bool is_changable(int n1, int n2) {
  int diff_cnt = 0;
  bool has_duplicate = false;
  bool digits_1[10];
  memset(digits_1, false, sizeof(digits_1));
  while(n1 != 0 && n2 != 0) {
	if(n1 % 10 != n2 % 10) diff_cnt += 1;
	if(digits_1[n1 % 10]) has_duplicate = true;
	digits_1[n1 % 10] = true;
	n1 /= 10;
	n2 /= 10;
  }
  if(n1 != 0 || n2 != 0) return false;
  if(diff_cnt == 2) return true;
  if(diff_cnt == 0 && has_duplicate) return true;
  return false;
}

int gofd(int num, int cnt) {
  if(dp[num][cnt] != -1) return dp[num][cnt];

  if(cnt == 0) {
	if(num == n) dp[num][cnt] = 1;
	else dp[num][cnt] = 0;
	return dp[num][cnt];
  }

  for(int candidate : candidates) {
	if(gofd(candidate, cnt - 1) == 1 && is_changable(candidate, num)) {
	  dp[num][cnt] = 1;
	  return dp[num][cnt];
	}
  }
  dp[num][cnt] = 0;
  return dp[num][cnt];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));
  cin >> n >> k;
  init_candidates();
  int res = -1;
  for(int candidate : candidates) {
	if(gofd(candidate, k) == 1) {
	  if(res == -1) res = candidate;
	  else res = max(res, candidate);
	}
  }
  cout << res << "\n";
  return 0;
}
