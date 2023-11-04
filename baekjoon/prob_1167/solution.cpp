#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int> > edges[100000];
vector<pair<int, int> > children[100000];

pair<int, int> dp[100000];

pair<int, int> gofd(int x) {
  if(dp[x].first != -1) return dp[x];

  vector<int> dists;
  for(auto child : children[x]) {
	dists.push_back(-1 * (gofd(child.first).first + child.second));
  }
  sort(dists.begin(), dists.end());
  if(dists.size() == 0) dp[x] = { 0, 0 };
  else if(dists.size() == 1) dp[x] = { -1 * dists[0], 0 };
  else dp[x] = { -1 * dists[0], -1 * dists[1] };
  return dp[x];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
	int target, v, len;
	cin >> target;
	while(true) {
	  cin >> v;
	  if(v == -1) break;
	  cin >> len;
	  edges[target - 1].push_back({v - 1, len});
	}
  }

  bool visited[100000];
  memset(visited, false, sizeof(visited));
  queue<int> q;
  q.push(0);
  visited[0] = true;
  while(!q.empty()) {
	int cur = q.front();
	q.pop();
	for(auto edge : edges[cur]) {
	  int next = edge.first;
	  int dist = edge.second;
	  if(visited[next]) continue;
	  q.push(next);
	  visited[next] = true;
	  children[cur].push_back({next, dist});
	}
  }

  for(int i = 0; i < n; i++) dp[i] = { -1, -1 };
  int res = 0;
  for(int i = 0; i < n; i++) {
	res = max(res, gofd(i).first + gofd(i).second);
  }
  cout << res << "\n";
  return 0;
}
