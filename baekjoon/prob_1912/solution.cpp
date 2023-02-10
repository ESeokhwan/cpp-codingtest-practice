#include <bits/stdc++.h>
using namespace std;

int n;

int nums[1000000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for(int i = 0; i < n; i++) {
	cin >> nums[i];
  }
  
  long long g_max = nums[0];
  long long cur = 0;
  for(int i = 0; i < n; i++) {
	if(cur < 0) {
	  cur = nums[i];
	} else {
	  cur += nums[i];
	}
	g_max = max(g_max, cur);
  }

  cout << g_max << "\n";
  cout << "\n";
  return 0;
}
