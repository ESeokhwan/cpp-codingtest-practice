#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll snow[600];
vector<ll> heights;
vector< pair<ll, pair<int, int> > > h_with_idx;
ll res = 9876543210;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> snow[i];

  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  if(i == j) continue;
	  heights.push_back(snow[i] + snow[j]);
	  h_with_idx.push_back(make_pair(snow[i] + snow[j], make_pair(i, j)));
	}
  }

  sort(heights.begin(), heights.end());
  sort(h_with_idx.begin(), h_with_idx.end());
  for(int i = 0; i < h_with_idx.size(); i++) {
	ll fh = h_with_idx[i].first;
	int idx = lower_bound(heights.begin(), heights.end(), fh) - heights.begin();

	int over_res_idx = idx;
	while(over_res_idx < h_with_idx.size()) {
	  int tmp = h_with_idx[over_res_idx].second.first;
	  if(tmp == h_with_idx[i].second.first || tmp == h_with_idx[i].second.second) {
		over_res_idx++;
		continue;
	  }

	  tmp = h_with_idx[over_res_idx].second.second;
	  if(tmp == h_with_idx[i].second.first || tmp == h_with_idx[i].second.second) {
		over_res_idx++;
		continue;
	  }
	  break;
	}
	
	int under_res_idx = idx - 1;
	while(under_res_idx >= 0) {
	  int tmp = h_with_idx[under_res_idx].second.first;
	  if(tmp == h_with_idx[i].second.first || tmp == h_with_idx[i].second.second) {
		under_res_idx--;
		continue;
	  }

	  tmp = h_with_idx[under_res_idx].second.second;
	  if(tmp == h_with_idx[i].second.first || tmp == h_with_idx[i].second.second) {
		under_res_idx--;
		continue;
	  }
	  break;
	}
	
	ll tmp_res;
	if(over_res_idx >= h_with_idx.size()) tmp_res = abs(h_with_idx[under_res_idx].first - h_with_idx[i].first);
	else if(under_res_idx < 0) tmp_res = abs(h_with_idx[over_res_idx].first - h_with_idx[i].first);
	else {
	  tmp_res = min(abs(h_with_idx[over_res_idx].first - h_with_idx[i].first), abs(h_with_idx[under_res_idx].first - h_with_idx[i].first));
	}

	res = min(res, tmp_res);
  }

  cout << res << "\n";
  return 0;
}
