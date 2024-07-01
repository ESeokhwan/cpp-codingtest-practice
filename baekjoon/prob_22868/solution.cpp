#include "bits/stdc++.h"
using namespace std;

int n, m;
int st, en;

vector<int> routes[100000];
int dists[100000];
int prevs[100000];

int already_pass[100000];

int cmp_prevs(int x, int y) {
  stack<int> x_path;
  stack<int> y_path;

  int tmp = x;
  while (tmp != -1) {
	x_path.push(tmp);
	tmp = prevs[tmp];
  }

  tmp = y;
  while (tmp != -1) {
	y_path.push(tmp);
	tmp = prevs[tmp];
  }

  while(!x_path.empty() && !y_path.empty()) {
	int cur_x = x_path.top();
	int cur_y = y_path.top();
	x_path.pop();
	y_path.pop();

	if (cur_x < cur_y) return -1;
	if (cur_y < cur_x) return 1;
  }
  return 0;
}

void dijk() {
  priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
  pq.push({0, { st, -1 } });
  while (!pq.empty()) { 
	int cost = pq.top().first;
	int cur_node = pq.top().second.first;
	int prev_node = pq.top().second.second;
	pq.pop();

	if (dists[cur_node] != -1 && dists[cur_node] < cost) {
	  continue;
	}
	
	if (dists[cur_node] != -1 && cmp_prevs(prevs[cur_node], prev_node) <= 0) {
	  continue;
	}

	dists[cur_node] = cost;
	prevs[cur_node] = prev_node;
	for (int next_node: routes[cur_node]) {
	  if (already_pass[next_node] || dists[next_node] != -1) continue;
	  pq.push({ cost + 1, { next_node, cur_node } });
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
	int input1, input2;
	cin >> input1 >> input2;
	routes[input1 - 1].push_back(input2 - 1);
	routes[input2 - 1].push_back(input1 - 1);
  }
  
  for (int i = 0; i < n; i++) {
	sort(routes[i].begin(), routes[i].end());
  }
  cin >> st >> en;
  st -= 1;
  en -= 1;
  
  memset(already_pass, false, sizeof(already_pass));
  memset(prevs, -1, sizeof(prevs));
  memset(dists, -1, sizeof(dists));

  dijk();

  int res = dists[en];
  int cur = en;
  while (cur != -1) {
	if (cur != en && cur != st) already_pass[cur] = true;
	cur = prevs[cur];
  }

  memset(prevs, -1, sizeof(prevs));
  memset(dists, -1, sizeof(dists));
  int tmp = en;
  en = st;
  st = tmp;
  dijk();
  cout << res + dists[en] << "\n";
  return 0;
}
