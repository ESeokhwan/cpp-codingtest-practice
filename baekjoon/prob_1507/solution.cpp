#include "bits/stdc++.h"
using namespace std;

int n, res;
int real_dist[20][20];

priority_queue<
  pair<int, pair<int, int> >, 
  vector<pair<int, pair<int, int> > >, 
  greater<pair<int, pair<int, int> > > 
> pq;

int cur_dist[20][20];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  cin >> real_dist[i][j];
	  if (i < j) {
		pq.push(make_pair(real_dist[i][j], make_pair(i, j)));
	  }
	}
  }

  memset(cur_dist, -1, sizeof(cur_dist));
  for (int i = 0; i < n; i++) {
	cur_dist[i][i] = 0;
  }

  res = 0;
  while(!pq.empty()) {
	int d = pq.top().first;
	int st = pq.top().second.first;
	int en = pq.top().second.second;
	pq.pop();

	if (cur_dist[st][en] != -1 && d >= cur_dist[st][en]) continue;
	
	cur_dist[st][en] = d;
	cur_dist[en][st] = d;
	res += d;

	for (int i = 0; i < n; i++) {
	  for (int j = 0; j < n; j++) {
		if (cur_dist[i][st] == -1 || cur_dist[en][j] == -1) continue;
		if (cur_dist[i][j] == -1 
			|| cur_dist[i][st] + d + cur_dist[en][j] < cur_dist[i][j]) {
		  cur_dist[i][j] = cur_dist[i][st] + d + cur_dist[en][j];
		  cur_dist[j][i] = cur_dist[i][j];
		}
	  }
	}
  }

  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  if (real_dist[i][j] != cur_dist[i][j]) {
		res = -1;
	  }
	}
  }
  
  cout << res << "\n";
  return 0;
}
