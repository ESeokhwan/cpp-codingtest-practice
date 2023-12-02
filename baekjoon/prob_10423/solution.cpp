#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int sps[1000];
vector<pair<int, int> > edges[1000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  for(int i = 0; i < k; i++) {
	int input;
	cin >> input;
	sps[i] = input - 1;
  }

  for(int i = 0; i < m; i++) {
	int input1, input2, input3;
	cin >> input1 >> input2 >> input3;
	edges[input2 - 1].push_back({ input3, input1 - 1 });
	edges[input1 - 1].push_back({ input3, input2 - 1 });
  }
  
  bool visited[1000];
  memset(visited, false, sizeof(visited));
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  for(int i = 0; i < k; i++) {
	for(auto edge: edges[sps[i]]) {
	  pq.push(edge);
	  visited[sps[i]] = true;
	}
  }

  int cnt = 0;
  int res = 0;
  while(cnt < n - k) {
	int cur_end = pq.top().second;
	int cur_val = pq.top().first;
	pq.pop();

	if(visited[cur_end]) continue;
	visited[cur_end] = true;
	cnt += 1;
	res += cur_val;
	for(auto edge: edges[cur_end]) pq.push(edge);
  }

  cout << res << "\n";
  return 0;
}
