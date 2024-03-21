#include <bits/stdc++.h>
using namespace std;

int n, m, d;
int board[15][15];

int get_subres(vector<int> archers) {
  int l_board[15][15];
  int res[15][15];
  memset(res, 0, sizeof(res));

  for (int r = 0; r < n; r++) {
	for (int c = 0; c < m; c++) {
	  l_board[r][c] = board[r][c];
	}
  }

  for (int t = 0; t < n; t++) {
	int c_dist[3] = { 50, 50, 50 };
	pair<int, int> pos[3] = { {16, 16}, {16, 16}, {16, 16} };
	for (int i = 0; i < archers.size(); i++) {
	  for (int r = n - t - 1; r >= 0; r--) {
		for (int c = 0; c < m; c++) {
		  if (l_board[r][c] == 0) continue;
		  int dist = n - r + abs(archers[i] - c) - t;
		  if (dist > c_dist[i] || dist > d) continue;
		  if (dist == c_dist[i] && c > pos[i].second) continue;
		  c_dist[i] = dist;
		  pos[i] = { r, c };
		}
	  }
	}
	for (int i = 0; i < archers.size(); i++) {
	  if (c_dist[i] == 50) continue;
	  res[pos[i].first][pos[i].second] = 1;
	  l_board[pos[i].first][pos[i].second] = 0;
	}
  }

  int output = 0;
  for (int r = 0; r < n; r++) {
	for (int c = 0; c < m; c++) {
	  output += res[r][c];
	}
  }
  return output;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> d;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	  cin >> board[i][j];
	}
  }
  
  int res = 0;
  for (int i = 0; i < m; i++) {
	for (int j = i + 1; j < m; j++) {
	  for (int k = j + 1; k < m; k++) {
		vector<int> ars;
		ars.push_back(i);
		ars.push_back(j);
		ars.push_back(k);
		res = max(res, get_subres(ars));
	  }
	}
  }

  cout << res << "\n";
  return 0;
}
