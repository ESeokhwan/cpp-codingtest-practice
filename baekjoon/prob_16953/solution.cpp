#include <bits/stdc++.h>
using namespace std;

long long a, b;

queue<pair<long long, int> > q;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> a >> b;

  bool is_all_exceed = false;
  bool has_answer = false;
  int cnt;
  q.push({ a, 1 });
  while(!q.empty()) {
	long long val = q.front().first;
	cnt = q.front().second;
	q.pop();
	if (val == b) {
	  break;
	}
	
	if (2 * val <= b) {
	  q.push({ 2 * val, cnt + 1 });
	}
	if (val * 10 + 1 <= b) {
	  q.push({ val * 10 + 1, cnt + 1});
	}
	cnt = -1;
  }

  cout << cnt << "\n";
  return 0;
}
