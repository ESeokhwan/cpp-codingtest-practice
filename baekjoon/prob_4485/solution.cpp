#include <bits/stdc++.h>
#define INF 9876543
using namespace std;

int n;
int z_map[125][125];
int dp[125][125];

pair<int, int> offs[4] = {
  make_pair(1, 0),
  make_pair(-1, 0),
  make_pair(0, 1),
  make_pair(0, -1)
};

priority_queue< pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cnt = 1;
  while(true) {
	memset(dp, INF, sizeof(dp));
	
	cin >> n;
	if(n == 0) break;
	for(int i = 0; i < n; i++) {
	  for(int j = 0; j < n; j++) cin >> z_map[i][j];
	}

	pq.push(make_pair(z_map[0][0], make_pair(0, 0)));
	while(!pq.empty()) {
	  int cur_coin = pq.top().first;
	  int cur_r = pq.top().second.first;
	  int cur_c = pq.top().second.second;
	  pq.pop();
	  if(cur_coin >= dp[cur_r][cur_c]) continue;

	  dp[cur_r][cur_c] = cur_coin;
	  for(auto off : offs) {
		int nr = cur_r + off.first;
		int nc = cur_c + off.second;	
		if(nr >= n || nr < 0 || nc >= n || nc < 0) continue;
		pq.push(make_pair(cur_coin + z_map[nr][nc], make_pair(nr, nc)));
	  }
	}
	cout << "Problem " << cnt << ": " << dp[n-1][n-1] << "\n";
	cnt++;
  }
  return 0;
}
