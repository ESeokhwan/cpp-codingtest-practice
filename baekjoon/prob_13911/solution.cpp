#include <bits/stdc++.h>
using namespace std;

int INF = 1000000000;

int v, e;
int m, x;
int s, y;
int res;
vector<pair<int, int> > edges[10002];
int mac_dist[10002];
int st_dist[10002];
int vertexes[10002];

void calc_mac() {
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  for(int i = 0; i < v + 1; i++) mac_dist[i] = INF;

  pq.push(make_pair(0, v));
  mac_dist[v] = 0;
  while(!pq.empty()) {
	int cur_pos = pq.top().second;
	int cur_dist = pq.top().first;
	pq.pop();

	for(int i = 0; i < edges[cur_pos].size(); i++) {
	  int n_pos = edges[cur_pos][i].second;
	  int a_dist = edges[cur_pos][i].first;
	  if(mac_dist[n_pos] > cur_dist + a_dist) {
		mac_dist[n_pos] = cur_dist + a_dist;
		pq.push(make_pair(cur_dist + a_dist, n_pos));
	  }
	}
  }
}

void calc_st() {
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  for(int i = 0; i < v + 1; i++) st_dist[i] = INF;

  pq.push(make_pair(0, v));
  st_dist[v] = 0;
  while(!pq.empty()) {
	int cur_pos = pq.top().second;
	int cur_dist = pq.top().first;
	pq.pop();

	for(int i = 0; i < edges[cur_pos].size(); i++) {
	  int n_pos = edges[cur_pos][i].second;
	  int a_dist = edges[cur_pos][i].first;
	  if(st_dist[n_pos] > cur_dist + a_dist) {
		st_dist[n_pos] = cur_dist + a_dist;
		pq.push(make_pair(cur_dist + a_dist, n_pos));
	  }
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(vertexes, 0, sizeof(vertexes));
  cin >> v >> e;
  for(int i = 0; i < e; i++) {
	int input[3];
	cin >> input[0] >> input[1] >> input[2];
	edges[input[0] - 1].push_back(make_pair(input[2], input[1] - 1));
	edges[input[1] - 1].push_back(make_pair(input[2], input[0] - 1));
  }
  
  cin >> m >> x;
  for(int i = 0; i < m; i++) {
	int input;
	cin >> input;
	vertexes[input - 1] = 1;
	edges[v].push_back(make_pair(0, input - 1));
  }
  calc_mac();

  edges[v].clear();
  cin >> s >> y;
  for(int i = 0; i < s; i++) {
	int input;
	cin >> input;
	vertexes[input - 1] = 2;
	edges[v].push_back(make_pair(0, input - 1));
  }
  calc_st();
  
  res = INF;
  for(int i = 0; i < v; i++) {
	if(vertexes[i] > 0) continue;
	if(mac_dist[i] > x) continue;
	if(st_dist[i] > y) continue;
	res = min(res, mac_dist[i] + st_dist[i]);
  }

  if(res == INF) res = -1;
  cout << res << "\n";
  return 0;
}
