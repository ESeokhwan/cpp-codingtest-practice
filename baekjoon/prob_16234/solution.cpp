#include <bits/stdc++.h>
using namespace std;

int N, L, R;

int po[50][50];
bitset<2500> reached;

vector< vector< pair < int, int > > > cop_list;

pair< int, int > offset_list[4] = {
  make_pair(1,0),
  make_pair(0,1),
  make_pair(-1,0),
  make_pair(0,-1)
};

int cnt;

void bfs(pair< int, int > sp) {
  queue< pair< int, int> > q;
  vector< pair<int, int> > cop;

  q.push(sp);
  cop.push_back(sp);
  reached.set(sp.first * 50 + sp.second);
  while(!q.empty()) {
	int cur_r = q.front().first;
	int cur_c = q.front().second;
	q.pop();

	for(pair< int, int > offset : offset_list) {
	  int next_r = cur_r + offset.first;
	  int next_c = cur_c + offset.second;
	  if(next_r >= N || next_r < 0 || next_c >= N || next_c < 0) continue;
	  if(reached.test(next_r * 50 + next_c)) continue;
	  if(abs(po[next_r][next_c] - po[cur_r][cur_c]) < L) continue;
	  if(abs(po[next_r][next_c] - po[cur_r][cur_c]) > R) continue;

	  q.push(make_pair(next_r, next_c));
	  cop.push_back(make_pair(next_r, next_c));
	  reached.set(next_r * 50 + next_c);
	}
  }
  
  if(cop.size() == 1) return;
  cop_list.push_back(cop);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> L >> R;

  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  cin >> po[i][j];
	}
  }

  cnt = -1;
  do {
	cop_list.clear();
	reached.reset();
	for(int i = 0; i < N; i++)
	  for(int j = 0; j < N; j++) bfs(make_pair(i, j));
	
	for(vector< pair < int, int > > cop : cop_list) {
	  int avg = 0;
	  for(pair< int, int > pos : cop) avg += po[pos.first][pos.second];
	  avg /= cop.size();

	  for(pair< int, int > pos : cop) po[pos.first][pos.second] = avg;
	}

	cnt++;
  } while(!cop_list.empty());


  cout << cnt << "\n";
  cout << "\n";
  return 0;
}

