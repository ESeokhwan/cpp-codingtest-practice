#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> pd[10000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n;
  for(int i = 0; i < n; i++) cin >> pd[i].second >> pd[i].first;
  sort(pd, pd + n);

  priority_queue<int, vector<int>, greater<int> > pq;
  for(int i = 0; i < n; i++) {
	int cur_p = pd[i].second;
	int cur_d = pd[i].first;
	if(cur_d <= pq.size()) {
	  if(pq.top() < cur_p) {
		pq.pop();
		pq.push(cur_p);
	  }
	} else {
	  pq.push(cur_p);
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
