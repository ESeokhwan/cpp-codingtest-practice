#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int, pair<int, int> > g[1000000];

int rt[100001];
int rk[100001];

int find(int a) {
  if(rt[a] == -1) rt[a] = a; 
  else if(rt[a] != a) rt[a] = find(rt[a]);
  return rt[a];
}

bool uni(int a, int b) {
  int ra = find(a);
  int rb = find(b);

  if(ra == rb) return false;
  if(rk[ra] > rk[rb]) rt[rb] = ra;
  else if(rk[ra] < rk[rb]) rt[ra] = rb;
  else {
	rt[rb] = ra;
	rk[ra]++;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(rk, 0, sizeof(rk));
  memset(rt, -1, sizeof(rt));

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
	cin >> g[i].second.first >> g[i].second.second >> g[i].first;
  }
  sort(g, g+m);

  int cnt = 0;
  int res = 0;
  int idx = 0;
  while(cnt < n - 2) {
	int price = g[idx].first;
	int p1 = g[idx].second.first;
	int p2 = g[idx].second.second;

	if(uni(p1, p2)) {
	  cnt += 1;
	  res += price;
	}
	idx++;
  }

  cout << res << "\n";
  return 0;
}
