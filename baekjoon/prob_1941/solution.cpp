#include <bits/stdc++.h>
using namespace std;

char _map[5][5];
int cur_state[5][5];
int ans;

pair<int, int> dirs[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

vector<pair<int, int> > getCandidates(pair<int, int> sp) {
  bool visited[5][5];
  queue<pair<int, int> > q;
  vector<pair<int, int> > output;
  memset(visited, false, sizeof(visited));

  q.push(sp);
  visited[sp.first][sp.second] = true;
  while(!q.empty()) {
	int cur_r = q.front().first;
	int cur_c = q.front().second;
	q.pop();

	for(auto dir: dirs) {
	  int next_r = cur_r + dir.first;
	  int next_c = cur_c + dir.second;
	  if(next_r < 0 || next_r >= 5 || next_c < 0 || next_c >= 5) continue;
	  if(visited[next_r][next_c]) continue;
	  visited[next_r][next_c] = true;
	  
	  if(cur_state[next_r][next_c] == -1) continue;
	  if(cur_state[next_r][next_c] == 1) q.push({next_r, next_c});
	  if(cur_state[next_r][next_c] == 0) output.push_back({next_r, next_c});
	}
  }
  return output;
}

void backtrack(int cnt, int s_cnt) {
  if(cnt >= 7 && s_cnt >= 4) {
	ans += 1;
	return;
  }
  if(7 - cnt < 4 - s_cnt) return;
  if(cnt >= 7) return;

  pair<int, int> sp;
  for(int i = 0; i < 5; i++) {
	for(int j = 0; j < 5; j++) {
	  if(cur_state[i][j] == 1) {
		sp = { i, j };
		break;
	  }
	}
  }

  vector<pair<int, int> > candidates = getCandidates(sp);
  for(auto new_person: candidates) {
	int new_cnt = cnt + 1;
	int new_s_cnt = s_cnt;
	if(_map[new_person.first][new_person.second] == 'S') new_s_cnt = s_cnt + 1;
	cur_state[new_person.first][new_person.second] = 1;
	backtrack(new_cnt, new_s_cnt);
	cur_state[new_person.first][new_person.second] = -1;
  }
  for(auto new_person: candidates) cur_state[new_person.first][new_person.second] = 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 0; i < 5; i++) {
	for(int j = 0; j < 5; j++) cin >> _map[i][j];
  }

  ans = 0;
  memset(cur_state, 0, sizeof(cur_state));
  for(int i = 0; i < 5; i++) {
	for(int j = 0; j < 5; j++) {
	  cur_state[i][j] = 1;
	  if(_map[i][j] == 'S') backtrack(1, 1);
	  else backtrack(1, 0);
	  cur_state[i][j] = -1;
	}
  }

  cout << ans << "\n";
  return 0;
}
