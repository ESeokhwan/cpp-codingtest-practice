#include <bits/stdc++.h>
using namespace std;

int n, m;
char _map[1000][1000];
int visited[1000][1000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(visited, 0, sizeof(visited));

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) cin >> _map[i][j];
  }

  int res = 0;
  int tick = 1;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	  if(visited[i][j] != 0) continue;
	  
	  int cur_r = i;
	  int cur_c = j;
	  while(visited[cur_r][cur_c] == 0) {
		visited[cur_r][cur_c] = tick;
		if(_map[cur_r][cur_c] == 'D') cur_r = cur_r + 1;
		else if(_map[cur_r][cur_c] == 'U') cur_r = cur_r - 1;
		else if(_map[cur_r][cur_c] == 'R') cur_c = cur_c + 1;
		else if(_map[cur_r][cur_c] == 'L') cur_c = cur_c - 1;
	  }
	  if(visited[cur_r][cur_c] == tick) res += 1;
	  tick++;
	}
  }

  cout << res << "\n";
  return 0;
}
