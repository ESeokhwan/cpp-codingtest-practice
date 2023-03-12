#include <bits/stdc++.h>
#define INF 5000000000000L

using namespace std;

typedef long long ll;
int n, m, k;

vector< pair<int, int> > edge[10000];

ll dp[10000][21];
bool visited[10000][21];

priority_queue< pair< ll, pair<int, int> >, vector< pair< ll, pair<int, int> > >, greater< pair< ll, pair<int, int> > > > pq;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 0; i < 10000; i++) {
	for(int j = 0; j < 21; j++) dp[i][j] = INF;
  }

  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
	int s, e, l;
	cin >> s >> e >> l;
	edge[s-1].push_back(make_pair(e-1, l));
	edge[e-1].push_back(make_pair(s-1, l));
  }

  dp[0][0] = 0;
  pq.push(make_pair(0, make_pair(0, 0)));

  while(!pq.empty()) {
	int cur_idx = pq.top().second.first;
	int cnt = pq.top().second.second;
	ll d = pq.top().first;
	pq.pop();
	
	if(visited[cur_idx][cnt]) continue;
	visited[cur_idx][cnt] = true;
	for(int i = 0; i < edge[cur_idx].size(); i++) {
	  int tar_idx = edge[cur_idx][i].first;
	  int l = edge[cur_idx][i].second;
	  if(dp[tar_idx][cnt] <= d + l) continue;
	  dp[tar_idx][cnt] = d + l;
	  pq.push(make_pair(d + l, make_pair(tar_idx, cnt)));
	}
	
	if(cnt >= k) continue;
	for(int i = 0; i < edge[cur_idx].size(); i++) {
	  int tar_idx = edge[cur_idx][i].first;
	  if(dp[tar_idx][cnt + 1] <= d) continue;
	  dp[tar_idx][cnt + 1] = d;
	  pq.push(make_pair(d, make_pair(tar_idx, cnt + 1)));
	}
  }

  ll res = INF;
  for(int i = 0; i <= k; i++) res = min(res, dp[n-1][i]);
  cout << res << "\n";
  return 0;
}
