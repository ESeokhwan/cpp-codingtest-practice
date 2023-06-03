#include <bits/stdc++.h>
using namespace std;

int INF = 100000000;

int t, n, m, w;
int roads[2500][3];
int worms[200][3];

int _map[500][500];
int total[500];

void init() {
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  _map[i][j] = INF;
	}
	total[i] = INF;
  }
}

void fill_map(int s, int e, int w) {
  _map[s][e] = min(_map[s][e], w);
}

void solution() {
  cin >> n >> m >> w;
  init();
  for(int i = 0; i < m; i++) {
	cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
	fill_map(roads[i][0] - 1, roads[i][1] - 1, roads[i][2]); 
	fill_map(roads[i][1] - 1, roads[i][0] - 1, roads[i][2]);
  }
  for(int i = 0; i < w; i++) {
	cin >> worms[i][0] >> worms[i][1] >> worms[i][2];
	fill_map(worms[i][0] - 1, worms[i][1] - 1, -1 * worms[i][2]);
  }

  bool has_cycle = false;
  total[0] = 0;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  for(int k = 0; k < n; k++) {
		if(_map[j][k] == INF) continue;
		if(total[k] > total[j] + _map[j][k]) {
		  total[k] = total[j] + _map[j][k];
		  if(i == n-1) has_cycle = true;
		}
	  }
	}
  }

  if(has_cycle) cout << "YES\n";
  else cout << "NO\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  for(int i = 0 ; i < t; i++) solution();
  return 0;
}
