#include <bits/stdc++.h>
using namespace std;

int T;

int n, m, t;
int s, g, h;

vector<pair<int, int> > routes[2005];
int cand[105];

void dijks(int st, int *dist) {
  memset(dist, -1, 2005 * sizeof(int));
  priority_queue<pair<int, int>, vector<pair<int, int > >, greater<pair<int, int> > > pq;
  pq.push({ 0, st });
  dist[st] = 0;
  while(!pq.empty()) {
	int cp = pq.top().second;
	int cd = pq.top().first;
	pq.pop();
	
	for (int i = 0; i < routes[cp].size(); i++) {
	  int np = routes[cp][i].first;
	  int nd = cd + routes[cp][i].second;
	  if (dist[np] == -1 || nd < dist[np]) {
		pq.push({ nd, np });
		dist[np] = nd;
	  }
	}
  }
}

void solution() {
  for(int i = 0; i < 2005; i++) routes[i].clear();

  cin >> n >> m >> t;
  cin >> s >> g >> h;

  int ghd;
  for (int i = 0; i < m; i++) {
	int a, b, d;
	cin >> a >> b >> d;
	routes[a - 1].push_back({b - 1, d});
	routes[b - 1].push_back({a - 1, d});
	if ((a == g && b == h) || (a == h && b == g)) {
	  ghd = d;
	}
  }

  for (int i = 0; i < t; i++) {
	int tmp;
	cin >> tmp;
	cand[i] = tmp - 1;
  }

  int d_from_s[2005];
  int d_from_h[2005];
  int d_from_g[2005];
  dijks(s - 1, d_from_s);
  dijks(h - 1, d_from_h);
  dijks(g - 1, d_from_g);

  vector<int> output;
  for (int i = 0; i < t; i++) {
	int ep = cand[i];
	int dist_using_gh = min(
		d_from_h[ep] + d_from_s[g - 1] + ghd,
		d_from_g[ep] + d_from_s[h - 1] + ghd
	);
	if (d_from_s[ep] == dist_using_gh) {
	  output.push_back(ep + 1);
	}
  }
  sort(output.begin(), output.end());
  for (int i : output) {
	cout << i << " ";
  }
  cout << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;
  for (int i = 0; i < T; i++) {
	solution();
  }
  return 0;
}
