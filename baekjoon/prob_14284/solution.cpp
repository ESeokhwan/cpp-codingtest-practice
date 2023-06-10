#include <bits/stdc++.h>
using namespace std;

int INF = 1000000;

int n, m;
int st, en;
int _map[5000][5000];
int dist[5000];

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  for(int i = 0; i < 5000; i++) {
	dist[i] = INF;
	for(int j = 0; j < 5000; j++) _map[i][j] = INF;
  }

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
	int t_st, t_en, t_dist;
	cin >> t_st >> t_en >> t_dist;
	t_st = t_st - 1;
	t_en = t_en - 1;
	_map[t_st][t_en] = min(_map[t_st][t_en], t_dist);
	_map[t_en][t_st] = min(_map[t_en][t_st], t_dist);
  }
  cin >> st >> en;
  st = st - 1;
  en = en - 1;

  pq.push(make_pair(0, st));
  while(!pq.empty()) {
	int cur_dist = pq.top().first;
	int cur_pos = pq.top().second;
	pq.pop();
	
	if(dist[cur_pos] != INF) continue;
	dist[cur_pos] = cur_dist;
	if(cur_pos == en) break;
	for(int i = 0; i < n; i++) {
	  if(_map[cur_pos][i] == INF) continue;
	  pq.push(make_pair(cur_dist + _map[cur_pos][i], i));
	}
  }
  cout << dist[en] << "\n";
  return 0;
}
