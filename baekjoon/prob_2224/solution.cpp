#include <bits/stdc++.h>

using namespace std;

int n;
char inputs[10000][2];
int graph[60][60];

vector<pair<char, char> > res;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(graph, 0, sizeof(graph));

  cin >> n;
  for(int i = 0; i < n; i++) {
	string del;
	cin >> inputs[i][0] >> del >> inputs[i][1];
  }
  for(int i = 0; i < n; i++) {
	graph[inputs[i][0] - 'A'][inputs[i][1] - 'A'] = 1;
  }

  for(int i = 0; i < 60; i++) {
	bool visited[60];
	memset(visited, false, sizeof(visited));

	queue<int> q;
	q.push(i);
	visited[i] = true;
	while(!q.empty()) {
	  int cur = q.front();
	  q.pop();
	  if(cur != i) res.push_back(make_pair(i + 'A', cur + 'A'));

	  for(int j = 0; j < 60; j++) {
		if(cur == j) continue;
		if(visited[j]) continue;
		if(graph[cur][j] == 1) {
		  q.push(j);
		  visited[j] = true;
		}
	  }
	}
  }
  sort(res.begin(), res.end());

  cout << res.size() << "\n";
  for(int i = 0; i < res.size(); i++) {
	cout << res[i].first << " => " << res[i].second << "\n";
  }
  return 0;
}
