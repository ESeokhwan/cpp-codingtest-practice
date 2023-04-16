#include <bits/stdc++.h>
using namespace std;

int v;
int e;

vector< pair<int, int> > rous[10000];
bool visited[10000];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(visited, false, sizeof(visited));

  cin >> v >> e;
  for(int i = 0; i < e; i ++) {
	int input[3];
	cin >> input[0] >> input[1] >> input[2];
	rous[input[0] - 1].push_back(make_pair(input[1] - 1, input[2]));
	rous[input[1] - 1].push_back(make_pair(input[0] - 1, input[2]));
  }

  int cnt = 0;
  int res = 0;
  int cur_v = 0;
  visited[0] = true;
  
  while(cnt < v - 1) {
	for(int i = 0; i < rous[cur_v].size(); i++) {
	  q.push(make_pair(rous[cur_v][i].second, rous[cur_v][i].first));
	}
	while(visited[q.top().second]) q.pop();
	cnt += 1;
	res += q.top().first;
	
	cur_v = q.top().second;
	visited[q.top().second] = true;
  }

  cout << res << "\n";
  return 0;
}
