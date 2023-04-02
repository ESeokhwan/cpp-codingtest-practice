#include <bits/stdc++.h>
using namespace std;

int n;
vector< pair<int, int> > xys;
vector< pair<int, int> > v;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
	int input[2];
	cin >> input[0] >> input[1];
	xys.push_back(make_pair(input[0], input[1]));
  }
  sort(xys.begin(), xys.end());
	
  v.push_back(xys[0]);
  for(int i = 1; i < n; i++) {
	if(v.back().second >= xys[i].first) v.back().second = max(v.back().second, xys[i].second);
	else v.push_back(xys[i]);
  }

  int res = 0;
  for(int i = 0; i < v.size(); i++) res += (v[i].second - v[i].first);
  cout << res << "\n";
  return 0;
}
