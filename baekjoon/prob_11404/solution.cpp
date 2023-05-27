#include <bits/stdc++.h>
using namespace std;

int n, m;
int edges[100][100];
int output[100][100];

void floyd(int x) {
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  pq.push(make_pair(0, x));

  while(!pq.empty()) {
	int val = pq.top().first;
	int idx = pq.top().second;
	pq.pop();
	if(output[x][idx] != -1) continue;
	output[x][idx] = val;

	for(int i = 0; i < n; i++) {
	  int cost = edges[idx][i];
	  if(output[x][i] != -1) continue;
	  if(cost == -1) continue; 
	  pq.push(make_pair(val + cost, i));
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(output, -1, sizeof(output));
  memset(edges, -1, sizeof(edges));
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
	int input[3];
	cin >> input[0] >> input[1] >> input[2];
	if(edges[input[0] - 1][input[1] - 1] == -1) {
	  edges[input[0] - 1][input[1] - 1] = input[2];
	} else {
	  edges[input[0] - 1][input[1] - 1] = 
		min(edges[input[0] - 1][input[1] - 1], input[2]);
	}
  }

  for(int i = 0; i < n; i++) floyd(i);
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  if(output[i][j] == -1) output[i][j] = 0;
	  cout << output[i][j] << " ";
	}
	cout << "\n";
  }
  cout << "\n";
  return 0;
}
