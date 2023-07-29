#include <bits/stdc++.h>
using namespace std;

int n, m;
int nums[7];

set<int> s;
int acc;

int pow(int x, int a) {
  int res = 1;
  for(int i = 0; i < a; i++) {
	res *= x;
  }
  return res;
}

void back_t(int idx) {
  if(n - idx < s.size()) return;
  if(idx == n) {
	acc += 1;
	return;
  }

  for(int i = 0; i < 10; i++) {
	bool isErased = false;
	if(s.count(i) != 0) {
	  s.erase(i);
	  isErased = true;
	}
	back_t(idx + 1);
	if(isErased) {
	  s.insert(i);
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < m; i++) cin >> nums[i];

  if(m == 0) {
	cout << pow(10, n) << "\n";
	return 0;
  }

  acc = 0;
  for(int i = 0; i < m; i++) s.insert(nums[i]);
  back_t(0);

  cout << acc <<"\n";
  return 0;
}
