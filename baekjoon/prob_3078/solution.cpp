#include <bits/stdc++.h>
using namespace std;

int n, k;
string names[300000];
long long friends[21];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for(int i = 0; i < n; i++) {
	cin >> names[i];
  }
  
  long long res = 0;
  memset(friends, 0L, sizeof(friends));
  for(int i = 0; i < n; i++) {
	if(i - k > 0) friends[names[i - k - 1].length()] -= 1;
	res += friends[names[i].length()];
	friends[names[i].length()] += 1;
  }

  cout << res << "\n";
  return 0;
}
