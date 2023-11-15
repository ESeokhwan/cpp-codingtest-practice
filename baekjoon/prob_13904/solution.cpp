#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> tasks[1000];

class PairComparison {
public:
  bool operator() (const pair<int, int>& lhs, const pair<int, int>&rhs) const {
	return lhs.second < rhs.second;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> tasks[i].first >> tasks[i].second;

  sort(tasks, tasks + n);
  priority_queue<int, vector<int>, greater<int> > pq;

  int cnt = 0;
  for(int i = 0; i < n; i++) {
	pq.push(tasks[i].second);
	cnt += 1;
	if(cnt > tasks[i].first) {
	  pq.pop();
	  cnt -= 1;
	}
  }

  int res = 0;
  while(!pq.empty()) {
	res += pq.top();
	pq.pop();
  }
  cout << res << "\n";
  return 0;
}
