#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[1000001][11];

int change(int num) {
  int m = 0;
  int nums[10];
  int tmp_nums[10];
  while(num != 0) {
	tmp_nums[m] = num % 10;
	num /= 10;
	m += 1;
  }
  for(int i = 0; i < m; i++) nums[i] = tmp_nums[m - i - 1];

  priority_queue<pair<int, int> > pq;
  for(int i = 0; i < m; i++) pq.push({ nums[i], i });
  int largestIdx = m - 1 < 0 ? 0 : m - 1;
  int targetIdx = m - 2 < 0 ? 0 : m - 2;

  int prev = -1;
  for(int i = 0; i < m; i++) {
	int val = pq.top().first;
	int idx = pq.top().second;
	pq.pop();
	if(val == nums[i]) {
	  stack<pair<int, int> > tmp_container;
	  tmp_container.push({ val, idx });
	  while(!pq.empty() && pq.top().first == nums[i]) {
		tmp_container.push(pq.top());
		pq.pop();
	  }
	  val = tmp_container.top().first;
	  idx = tmp_container.top().second;
	  tmp_container.pop();
	  while(!tmp_container.empty()) {
		pq.push(tmp_container.top());
		tmp_container.pop();
	  }
	}
	cout << i << ":" << nums[i] << " " << idx << ":"  << val << "\n";
	if(i != 0 && nums[i] == prev) {
	  largestIdx = i;
	  targetIdx = i - 1;
	}
    prev = nums[i];

	if(i < idx && nums[i] != nums[idx]) {
	  largestIdx = idx;
	  targetIdx = i;
	  break;
	}
  }
  cout << "largest Idx : " << largestIdx << " targetIdx" << targetIdx << "\n";
  cout << "\n";
  
  if((nums[largestIdx] == 0 && targetIdx == 0) || largestIdx == targetIdx) return 0;

  int tmp = nums[largestIdx];
  nums[largestIdx] = nums[targetIdx];
  nums[targetIdx] = tmp;
  int res = 0;
  for(int i = 0; i < m; i++) {
	res *= 10;
	res += nums[i];
  }
  return res;
}

int change2(int num) {
  int m = 0;
  int nums[10];
  int tmp_nums[10];
  while(num != 0) {
	tmp_nums[m] = num % 10;
	num /= 10;
	m += 1;
  }
  for(int i = 0; i < m; i++) nums[i] = tmp_nums[m - i - 1];

  int res = 0;
  for(int i = 0; i < m; i++) {
	for(int j = i + 1; j < m; j++) {
	  if(i == 0 && nums[j] == 0) continue;
	  int tmp = nums[i];
	  nums[i] = nums[j];
	  nums[j] = tmp;
	  
	  int sub_res = 0;
	  for(int i = 0; i < m; i++) {
		sub_res *= 10;
		sub_res += nums[i];
	  }
	  res = max(res, sub_res);

	  tmp = nums[i];
	  nums[i] = nums[j];
	  nums[j] = tmp;
	}
  }
  return res;
}

int res;
int m;
int nums[10];
void change3(int cnt, int idx1, int idx2) {
  int tmp = nums[idx1];
  nums[idx1] = nums[idx2];
  nums[idx2] = tmp;

  if(cnt == k) {
	int sub_res = 0;
	for(int i = 0; i < m; i++) {
	  sub_res *= 10;
	  sub_res += nums[i];
	}
	res = max(res, sub_res);
  } else {
    for(int i = 0; i < m; i++) {
  	  for(int j = i + 1; j < m; j++) {
	    if(i == 0 && nums[j] == 0) continue;
	    change3(cnt + 1, i, j);
	  }
	}
  }

  tmp = nums[idx1];
  nums[idx1] = nums[idx2];
  nums[idx2] = tmp;
}

void rec(int cnt) {
  if(cnt == k) {
	int sub_res = 0;
	for(int i = 0; i < m; i++) {
	  sub_res *= 10;
	  sub_res += nums[i];
	}
	res = max(res, sub_res);
	return;
  }
}


int gofd(int num, int cnt) {
  if(dp[num][cnt] != -1) return dp[num][cnt];

  if(cnt == 0) {
	dp[num][cnt] = num;
	return dp[num][cnt];
  }
  dp[num][cnt] = change2(gofd(num, cnt - 1));
  return dp[num][cnt];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));
  cin >> n >> k;
  int tmp = n;
  m = 0;
  res = -1;
  int tmp_nums[10];
  while(tmp != 0) {
	tmp_nums[m] = tmp % 10;
	tmp /= 10;
	m += 1;
  }
  for(int i = 0; i < m; i++) nums[i] = tmp_nums[m - i - 1];
  for(int i = 0; i < m; i++) {
	for(int j = i + 1; j < m; j++) {
	  if(i == 0 && nums[j] == 0) continue;
	  change3(1, i, j);
	}
  }

  cout << res << "\n";
  return 0;
}
