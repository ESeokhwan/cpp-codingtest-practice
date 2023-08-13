#include <bits/stdc++.h>
using namespace std;

int n;
int nums[1000];
long long res[1000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
	cin >> nums[i];
  }
  sort(nums, nums + n);

  if(nums[0] == 1) res[0] = 2;
  else res[0] = 1;
  for(int i = 1; i < n; i++) {
	if(res[i - 1] >= nums[i]) res[i] = res[i - 1] + nums[i];
	else res[i] = res[i - 1];
  }

  cout << res[n - 1] << "\n";
  return 0;
}
