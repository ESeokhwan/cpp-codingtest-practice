#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int n, k, s;

int incidents[510];
set<int> after_that[510];
pair<int, set<int> > all_after_that[510];

void init_all_after_that() {
  for (int i = 1; i <= n; i++) {
	all_after_that[i].first = -1;
  }
}

void set_all_after_that(int st) {
  queue<int> q;
  int visited[510];
  memset(visited, 0, sizeof(visited));

  q.push(st);
  visited[st] = 1;
  while(!q.empty()) {
	int cur = q.front();
	q.pop();
	all_after_that[st].second.insert(cur);

	for (int nx: after_that[cur]) {
	  if (visited[nx] == 1) continue;
	  q.push(nx);
	  visited[nx] = 1;
	}
  }
  all_after_that[st].first = 1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
	int input1, input2;
	cin >> input1 >> input2;
	after_that[input1].insert(input2);
  }
  init_all_after_that();

  cin >> s;
  for (int i = 0; i < s; i++) {
	int input1, input2;
	cin >> input1 >> input2;
	if (all_after_that[input1].first == -1) set_all_after_that(input1);
	if (all_after_that[input2].first == -1) set_all_after_that(input2);

	if (all_after_that[input1].second.count(input2) > 0) {
	  cout << -1;
	} else if (all_after_that[input2].second.count(input1) > 0) {
	  cout << 1;
	} else {
	  cout << 0;
	}
	cout << "\n";
  }
  return 0;
}
