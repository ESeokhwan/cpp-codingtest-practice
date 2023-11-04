#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int points[10000];

bool check(int x) {
  int prev_idx = 0;
  int check_point = 0;
  for(int i = 0; i < l; i++) {
	int cur_boundary = (upper_bound(points, points + k, check_point + x) - points);
	if(prev_idx == cur_boundary) return false;
	check_point = points[cur_boundary - 1];
	prev_idx = cur_boundary - 1;
	if(check_point + x >= n) return true;
  }
  return false;
}

bool check2(int x, int start_pos) {
  int prev_idx = 0;
  int check_point = start_pos;
  if(l == 1) return check_point + x >= n;
  for(int i = 0; i < l - 1; i++) {
	int cur_boundary = (upper_bound(points, points + k, check_point + x) - points);
	if(prev_idx == cur_boundary) return false;
	check_point = points[cur_boundary - 1];
	prev_idx = cur_boundary - 1;
	if(check_point + x >= n) return true;
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k >> l;
  for(int i = 0; i < k; i++) cin >> points[i];
  sort(points, points + k);

  int st = 1;
  int en = n;
  while(st < en) {
	int mid = (st + en) / 2;
	if(check(mid)) {
	  en = mid;
	} else {
	  st = mid + 1;
	}
  }

  int cnt = 0;
  int res;
  while(points[cnt] <= st) {
	if(check2(st, points[cnt])) {
	  res = points[cnt];
	  break;
	}
	cnt += 1;
  }

  cout << st << " " << res << "\n";
  return 0;
}
