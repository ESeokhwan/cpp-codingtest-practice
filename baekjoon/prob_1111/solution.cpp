#include <bits/stdc++.h>
using namespace std;

int n;
int nums[50];

int a, b;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> nums[i];

  if(n == 1) {
	cout << "A\n";
	return 0;
  }
  if(n == 2) {
	if(nums[0] == nums[1]) cout << nums[0] << "\n";
	else cout << "A\n";
	return 0;
  }

  bool has_rt = false;
  if(nums[2] == nums[1]) {
	has_rt = true;
	a = 0;
	b = nums[1];
  } else if((nums[1] != nums[0]) && ((nums[2] - nums[1]) % (nums[1] - nums[0]) == 0)) {
	has_rt = true;
	a = (nums[2] - nums[1]) / (nums[1] - nums[0]);
	b = nums[2] - a * nums[1];
  }
  
  for(int i = 3; has_rt && i < n; i++) {
	if(nums[i] == nums[i - 1] * a + b) continue;
	has_rt = false;
  }
  if(has_rt) cout << nums[n - 1] * a + b << "\n";
  else cout << "B\n";
  return 0;
}
