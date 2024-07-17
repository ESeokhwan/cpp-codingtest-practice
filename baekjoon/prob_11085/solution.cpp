#include <bits/stdc++.h>
using namespace std;

int p, w, c, v;
vector<pair<int, int> > edges[1005];
priority_queue<pair<int, pair<int, int> > > pq; 

int visited[1005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> p >> w;
  cin >> c >> v;
  for (int i = 0; i < w; i++) {
	int input[3];
	cin >> input[0] >> input[1] >> input[2];
	edges[input[0]].push_back({ input[1], input[2] });
	edges[input[1]].push_back({ input[0], input[2] });
  }

  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < edges[c].size(); i++) {
	pq.push({ edges[c][i].second, { c, edges[c][i].first } });
  }

  int res = 987765431;
  while(!pq.empty()) {
	int width = pq.top().first;
	int nxt = -1;
	if (visited[pq.top().second.first] == 0) {
	  nxt = pq.top().second.first;
	} else if (visited[pq.top().second.second] == 0) {
	  nxt = pq.top().second.second;
	}
	pq.pop();
	if (nxt == -1) continue;
	visited[nxt] = 1;
	res = min(res, width);
	if (nxt == v) break;
	
	for (auto edge: edges[nxt]) {
	  pq.push({ edge.second, { nxt, edge.first } });
	}
  }
  cout << res << "\n";
  return 0;
}

