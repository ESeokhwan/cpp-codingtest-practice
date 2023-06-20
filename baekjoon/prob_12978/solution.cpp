#include <bits/stdc++.h>
using namespace std;

int n;
int input[2];

vector<int> edges[100000];
int deg[100000];
bool excluded[100000];

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(deg, 0, sizeof(deg));
  memset(excluded, false, sizeof(excluded));
  cin >> n;
  for(int i = 0; i < n; i++) {
	cin >> input[0] >> input[1];
	edges[input[0] - 1].push_back(input[1] - 1);
	edges[input[1] - 1].push_back(input[0] - 1);
	deg[input[0] - 1] += 1;
	deg[input[1] - 1] += 1;
  }
  for(int i = 0; i < n; i++) pq.push(make_pair(deg[i], i));

  int cnt = 0;
  while(!pq.empty()) {
	int cur_pos = pq.top().second;
	int cur_deg = pq.top().first;
	pq.pop();
	if(excluded[cur_pos]) continue;
	excluded[cur_pos] = true;
	
	if(cur_deg == 0) continue;
	int selected;
	for(int i = 0; i < edges[cur_pos].size(); i++) {
	  if(excluded[edges[cur_pos][i]]) continue;
	  selected = edges[cur_pos][i];
	}
	excluded[selected] = true;
	cnt += 1;

	for(int i = 0; i < edges[selected].size(); i++) {
	  int nx_p = edges[selected][i];
	  if(excluded[edges[selected][i]]) continue;
	  deg[nx_p] -= 1;
	  pq.push(make_pair(deg[nx_p], nx_p));
	}
  }

  cout << cnt << "\n"; 
  return 0;
}
