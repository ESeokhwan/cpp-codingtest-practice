#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int nums[4000000];
int nexts[4000000];
pair<int, int> chs[10000];

int res[10000];

int find(int x) {
  if(nexts[x] == x) return x;
  return (nexts[x] = find(nexts[x]));
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
	cin >> nums[i];
	nexts[i] = i;
  }

  for(int i = 0; i < k; i++) {
	cin >> chs[i].first;
	chs[i].second = i;
  }

  sort(nums, nums + m);

  for(int i = 0; i < k; i++) {
	int idx = (upper_bound(nums, nums + m, chs[i].first) - nums);
	idx = find(idx);
	res[i] = nums[idx];
	nexts[idx] = idx + 1;
  }

  for(int i = 0; i < k; i++) cout << res[i] << "\n";

  return 0;
}
