#include <bits/stdc++.h>
using namespace std;

int g, p;
int input[100000];
set<int> b_front;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> g >> p;
  for(int i = 0; i < p; i++) {
	cin >> input[i];
  }
  for(int i = 0; i < g; i++) b_front.insert(-1 * (i + 1));

  int res = 0;
  for(int i = 0; i < p; i++) {
	if(b_front.size() == 0) break;
	auto it = b_front.lower_bound(-1 * input[i]);
	if(it == b_front.end()) break;
	b_front.erase(it);
	res = i + 1;
  }

  cout << res <<  "\n";
  return 0;
}
