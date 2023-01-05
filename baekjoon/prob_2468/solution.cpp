#include <bits/stdc++.h>
using namespace std;

int N;
int h_info[105][105];
bool is_dirty[105][105];
int max_height, max_cnt;

int us_height, local_cnt;

bool traverse(pair<int, int> sp) {
  queue< pair<int, int> > que;

  if(is_dirty[sp.first][sp.second]) return false;
  if(h_info[sp.first][sp.second] <= us_height) return false;

  que.push(sp);
  is_dirty[sp.first][sp.second] = true;
  while(!que.empty()) {
	pair<int, int> cn = que.front();
	que.pop();

	pair<int, int> children[4];
	children[0] = make_pair(cn.first + 1, cn.second);
	children[1] = make_pair(cn.first, cn.second + 1);
	children[2] = make_pair(cn.first - 1, cn.second);
	children[3] = make_pair(cn.first, cn.second - 1);

	for(pair<int, int> child : children) {
	  if(child.first < 0 || child.first >= N || 
		  child.second < 0 || child.second >= N) continue;
	  if(is_dirty[child.first][child.second]) continue;
	  if(h_info[child.first][child.second] <= us_height) continue;
	  que.push(child);
	  is_dirty[child.first][child.second] = true;
	}
  }
  return true;
}

void init_is_dirty() {
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  is_dirty[i][j] = false;
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  
  max_height = 0;
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  cin >> h_info[i][j];
	  if(h_info[i][j] > max_height) max_height = h_info[i][j];
	}
  }

  max_cnt = 0;
  for(int i = 0; i < max_height + 1; i++) {
	us_height = i;
	local_cnt = 0;
	init_is_dirty();
	for(int j = 0; j < N; j++) {
	  for(int k = 0; k < N; k++) {
		if(traverse(make_pair(j, k))) local_cnt++;
	  }
	}
	if(local_cnt > max_cnt) max_cnt = local_cnt;
  }

  cout << max_cnt << "\n";

  cout << "\n";
  return 0;
}
