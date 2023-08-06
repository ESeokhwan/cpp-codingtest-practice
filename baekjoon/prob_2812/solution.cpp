#include <bits/stdc++.h>
using namespace std;

int n, k;
pair<int, int> nums[500000];

pair<int, int> res[500000];

bool cmp(pair<int, int> a, pair<int, int> b) { 
  if(a.first == b.first) {
	return a.second > b.second;
  }
  return a.first > b.first; 
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string input;
  cin >> n >> k;
  cin >> input;
  for(int i = 0; i < n; i++) {
	nums[i].first = input[i] - '0';
	nums[i].second = n - i - 1;
  }
  sort(nums, nums + n, cmp);

  int ub = n - k - 1;
  int lb = 0;
  for(int i = 0; i < n - k; i++) res[i] = make_pair(-1, -1);
  for(int i = 0; i < n; i++) {
	if((ub < n - k - 1 && nums[i].second > res[ub + 1].second) 
		|| (lb > 0 && nums[i].second < res[lb - 1].second)) {
	  continue;
	}
	int pos = min(nums[i].second, ub);
	res[pos] = nums[i];

	while(ub > 0 && res[ub].first != -1) ub -= 1;
	while(lb <= n - k - 1 && res[lb].first != -1) lb += 1;

	if(lb > ub) break;

  }

  for(int i = n - k - 1; i >= 0; i--) cout << res[i].first;
  cout << "\n";
  return 0;
}
