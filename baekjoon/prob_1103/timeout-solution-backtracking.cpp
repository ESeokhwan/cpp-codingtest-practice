#include <bits/stdc++.h>

using namespace std;

int N, M;
char g_map[50][50];
bool visited[50][50];

int r_off[4] = {1, -1, 0, 0};
int c_off[4] = {0, 0, 1, -1};

int res;

void traverse(int acc, int cr, int cc) {
  if(res == -1) return;
  if(cr < 0 || cr >= N || cc < 0 || cc >= M) {
	res = max(res, acc);
	return;
  }
  if(g_map[cr][cc] == 'H') {
	res = max(res, acc);
	return;
  }
  if(visited[cr][cc] == true) {
	res = -1;
	return;
  }

  int num = (int) (g_map[cr][cc] - '0');
  visited[cr][cc] = true;
  for(int i = 0; i < 4; i++) traverse(acc+1, cr + r_off[i] * num, cc + c_off[i] * num);
  visited[cr][cc] = false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  res = 0;
  for(int i = 0; i < N; i++) memset(visited[i], false, sizeof(bool)*M);

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < M; j++) {
	  cin >> g_map[i][j];
	}
  }

  traverse(0, 0, 0);
  cout << res << "\n";
  return 0;
}

