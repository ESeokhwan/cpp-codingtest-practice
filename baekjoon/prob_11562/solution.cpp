#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<int, int> > gra[250];
int res[250][250];

void dijk(int st) {
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  pq.push(make_pair(0, st));
  while(!pq.empty()) {
	int cur_pos = pq.top().second;
	int cur_dist = pq.top().first;
	pq.pop();
	if(res[st][cur_pos] != -1 && res[st][cur_pos] <= cur_dist) continue;
	res[st][cur_pos] = cur_dist;

	for(int i = 0; i < gra[cur_pos].size(); i++) {
	  if(res[st][gra[cur_pos][i].first] == -1) {
		pq.push(make_pair(cur_dist + gra[cur_pos][i].second, gra[cur_pos][i].first));
	  }
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
	int input[3];
	cin >> input[0] >> input[1] >> input[2];

	gra[input[0] - 1].push_back(make_pair(input[1] - 1, 0));
	if(input[2] == 1) gra[input[1] - 1].push_back(make_pair(input[0] - 1, 0));
	if(input[2] == 0) gra[input[1] - 1].push_back(make_pair(input[0] - 1, 1));
  }

  memset(res, -1, sizeof(res));
  for(int i = 0; i < n; i++) dijk(i);

  cin >> k;
  for(int i = 0; i < k; i++) {
	int input[2];
	cin >> input[0] >> input[1];

	cout << res[input[0] - 1][input[1] - 1] << "\n";
  }
  return 0;
}
