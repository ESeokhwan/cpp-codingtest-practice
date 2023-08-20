#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int> > gra[100000];
int dist[100000];
int st, en;

bool can_reach(int weight) {
  memset(dist, -1, sizeof(dist));
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

  dist[st] = 0;
  pq.push(make_pair(0, st));
  while(!pq.empty()) {
	int cur_pos = pq.top().second;
	int cur_dist = pq.top().first;
	pq.pop();

	if(cur_pos == en) break;
	for(int i = 0; i < gra[cur_pos].size(); i++) {
	  int acc;
	  if(gra[cur_pos][i].second < weight) acc = 1;
	  else acc = 0;
	  
	  int next_pos = gra[cur_pos][i].first;
	  int next_dist = cur_dist + acc;
	  if(dist[next_pos] == -1 || next_dist < dist[next_pos]) {
		dist[next_pos] = next_dist;
		pq.push(make_pair(next_dist, next_pos));
	  }
	}
  }

  return dist[en] == 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
	int a, b, c;
	cin >> a >> b >> c;
	gra[a - 1].push_back(make_pair(b - 1, c));
	gra[b - 1].push_back(make_pair(a - 1, c));
  }
  cin >> st >> en;
  st -= 1;
  en -= 1;

  int bi_st, bi_en, bi_mid;
  bi_st = 0;
  bi_en = 1000000001;
  while(bi_st < bi_en) {
	bi_mid = (bi_st + bi_en) / 2;
    if(can_reach(bi_mid)) bi_st = bi_mid + 1;
	else bi_en = bi_mid;
  }

  cout << bi_st - 1 << "\n";
  return 0;
}
