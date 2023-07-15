#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
pair<ll, ll> v[1500];

ll len_square(pair<ll, ll> a, pair<ll, ll> b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

  int cnt = 0;
  for(int i = 0; i < n; i++) {
	for(int j = i + 1; j < n; j++) {
	  for(int k = j + 1; k < n; k++) {
		ll lines[3];
		lines[0] = len_square(v[i], v[j]);
		lines[1] = len_square(v[j], v[k]);
		lines[2] = len_square(v[k], v[i]);
		
		if(lines[0] == lines[1] + lines[2] 
			|| lines[1] == lines[0] + lines[2] || lines[2] == lines[0] + lines[1]) {
		  cnt += 1;
		}
	  }
	}
  }

  cout << cnt << "\n";
  return 0;
}
