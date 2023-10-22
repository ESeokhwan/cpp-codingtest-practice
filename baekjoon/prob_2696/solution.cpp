#include <bits/stdc++.h>
using namespace std;

int t;

void solution() {
  int m;
  int nums[9999];
  priority_queue<int> h_pq;
  priority_queue<int, vector<int>, greater<int> > l_pq;

  cin >> m;
  for(int i = 0; i < m; i++) cin >> nums[i];

  int mid_cnt = (m + 1) / 2;
  cout << mid_cnt << "\n";
  int cur_mid;
  for(int i = 0; i < mid_cnt; i++) {
	if(i == 0) {
	  cur_mid = nums[0];
	  l_pq.push(nums[0]);
	  h_pq.push(nums[0]);
	  cout << cur_mid << " ";
	  continue;
	}

	if(i % 10 == 0) cout << "\n";
	int new_num1 = nums[i * 2 - 1];
	int new_num2 = nums[i * 2];
	if(cur_mid <= new_num1 && cur_mid <= new_num2) {
	  l_pq.push(new_num1);
	  l_pq.push(new_num2);
	  l_pq.pop();
	  h_pq.push(l_pq.top());
	} else if(cur_mid > new_num1 && cur_mid > new_num2) {
	  h_pq.push(new_num1);
	  h_pq.push(new_num2);
	  h_pq.pop();
	  l_pq.push(h_pq.top());
	} else {
	  l_pq.push(max(new_num1, new_num2));
	  h_pq.push(min(new_num1, new_num2));
	}
	cur_mid = l_pq.top();
	cout << cur_mid << " ";
  }
  cout << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  for(int i = 0; i < t; i++) solution();
  return 0;
}
