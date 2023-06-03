#include <bits/stdc++.h>
using namespace std;

int INF = 1000000000;

int n;
pair<int, int> lines[100000];

int nums[100000];
int idxes[100000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) nums[i] = INF;
  for(int i = 0; i < n; i++) cin >> lines[i].first >> lines[i].second;
  sort(lines, lines + n);

  int cnt = 0;
  for(int i = 0; i < n; i++) {
	int idx = (lower_bound(nums, nums + n, lines[i].second) - nums);
	if(idx == cnt) cnt += 1;
	nums[idx] = lines[i].second;
	idxes[i] = idx;
  }

  cout << n - cnt << "\n";
  cnt -= 1;
  for(int i = n; i >= 0; i--) {
	if(idxes[i] == cnt) {
	  lines[i].first = -1;
	  cnt -= 1;
	}
  }

  for(int i = 0; i < n; i++) {
	if(lines[i].first == -1) continue;
	cout << lines[i].first << "\n";
  }
  return 0;
}
