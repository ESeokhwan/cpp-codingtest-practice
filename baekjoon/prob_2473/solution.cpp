#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<ll> acids;
vector<ll> res;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  res.push_back(9876543210);
  res.push_back(9876543210);
  res.push_back(9876543210);

  cin >> n;
  for(int i = 0; i < n; i++) {
	int input;
	cin >> input;
	acids.push_back(input);
  }
  sort(acids.begin(), acids.begin() + n);
  
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  if(i == j) continue;

	  ll sum_of_two = acids[i] + acids[j];
	  int idx = (lower_bound(acids.begin(), acids.begin() + n, -1 * sum_of_two) - acids.begin());
	  if(idx >= n) idx = n-1;

	  int over_res_idx = idx;
	  while(over_res_idx == i || over_res_idx == j) {
		over_res_idx++;
	  }
	
	  int under_res_idx = idx - 1;
	  while(under_res_idx == i || under_res_idx == j) {
		under_res_idx--;
	  }

	  ll tmp_res;
	  if(over_res_idx >= n) {
		tmp_res = acids[under_res_idx];
	  } else if(under_res_idx <= -1) {
		tmp_res = acids[over_res_idx];
	  } else if(abs(acids[under_res_idx] + sum_of_two) > abs(acids[over_res_idx] + sum_of_two)) {
		tmp_res = acids[over_res_idx];
	  } else {
		tmp_res = acids[under_res_idx];
	  }

	  if(abs(res[0] + res[1] + res[2]) > abs(tmp_res + sum_of_two)) {
		res[0] = acids[i];
		res[1] = acids[j];
		res[2] = tmp_res;
	  }
	}
  }

  sort(res.begin(), res.end());
  cout << res[0] << " " << res[1] << " " << res[2] << "\n";
  return 0;
}

