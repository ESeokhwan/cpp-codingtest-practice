#include <bits/stdc++.h>
using namespace std;

int n;
int input[1000000];
vector<int> tmp;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> input[i];

  int cnt = 0;
  for(int i = 0; i < n; i++) {
	auto iter = lower_bound(tmp.begin(), tmp.end(), input[i]);
	if(iter == tmp.end()) tmp.push_back(input[i]);
	else *iter = input[i];
  }

  cout << tmp.size() << "\n";
  return 0;
}

