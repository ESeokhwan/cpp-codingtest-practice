#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
ll nums[1000000];
int prev_idx[1000000];

vector<ll> tail;
vector<int> tail_idx;

stack<int> res;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(prev_idx, -1, sizeof(prev_idx));

  cin >> N;
  for(int i = 0; i < N; i++) cin >> nums[i];
  
  for(int i = 0; i < N; i++) {
	auto lo = lower_bound(tail.begin(), tail.end(), nums[i]);
	int idx = (int) (lo - tail.begin());
	if(lo == tail.end()) {
	  tail.push_back(nums[i]);
	  tail_idx.push_back(i);
	} else {
	  tail[idx] = nums[i];
	  tail_idx[idx] = i;
	}
	if(idx == 0) prev_idx[i] = -1;
	else prev_idx[i] = tail_idx[idx-1];
  }

  cout << tail.size() << "\n";

  
  int idx = tail_idx.back();
  do {
	res.push(nums[idx]);
	idx = prev_idx[idx];
  } while(idx != -1);

  while(!res.empty()) {
	cout << res.top() << " ";
	res.pop();
  }
  cout << "\n";
  return 0;
}
