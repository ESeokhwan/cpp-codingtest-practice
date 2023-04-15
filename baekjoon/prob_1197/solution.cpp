#include <bits/stdc++.h>
using namespace std;

int v;
int e;

pair<int, pair<int, int> > edges[100000];
int root[10001];
int he[10001];

void reset() {
  memset(he, 0, sizeof(he));
  for(int i = 0; i <= v; i++) root[i] = i;
}

int find(int x) {
  if(root[x] == x) {
	return x;
  }
  return root[x] = find(root[x]);
}

bool conc(int x, int y) {
  int rx = find(x);
  int ry = find(y);

  if(rx == ry) return 0;
  
  if(he[rx] > he[ry]) root[ry] = rx;
  else if(he[rx] < he[ry]) root[rx] = ry;
  else {
	root[ry] = rx;
	he[rx] += 1;
  }
  return 1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> v >> e;
  for(int i = 0; i < e; i ++) {
	cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
  }
  reset();

  sort(edges, edges+e);

  int cnt = 0;
  int res = 0;
  for(int i = 0; i < e; i++) {
	if(cnt == v-1) break;

	int cur_val = edges[i].first;
	int cur_s = edges[i].second.first;
	int cur_e = edges[i].second.second;

	if(conc(cur_s, cur_e)) {
	  cnt += 1;
	  res += cur_val;
	}
  }

  cout << res  << "\n";
  return 0;
}
