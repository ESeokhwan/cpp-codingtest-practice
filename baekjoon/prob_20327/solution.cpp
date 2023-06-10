#include <bits/stdc++.h>
using namespace std;

int N, R;
int po_N;
pair<int, int> input[1000];
int _map[128][128];
int tmp_map[128][128];

void map_flush() {
  for(int i = 0; i < po_N; i++) {
	for(int j = 0; j < po_N; j++) _map[i][j] = tmp_map[i][j];
  }
}

void p1_sub(int r, int c, int n) {
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) tmp_map[r + (n - i - 1)][c + j] = _map[r + i][c + j];
  }
}

void p2_sub(int r, int c, int n) {
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) tmp_map[r + i][c + (n - j - 1)] = _map[r + i][c + j];
  }
}

void p3_sub(int r, int c, int n) {
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) tmp_map[r + i][c + j] = _map[r + (n - 1 -j)][c + i];
  }
}

void p4_sub(int r, int c, int n) {
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) tmp_map[r + i][c + j] = _map[r + j][c + (n - 1 - i)];
  }
}

void p1(int l) {
  int n = 1;
  for(int i = 0; i < l; i++) n *= 2;
  for(int i = 0; i < po_N; i = i + n) {
	for(int j = 0; j < po_N; j = j + n) p1_sub(i, j, n);
  }
  map_flush();
}

void p2(int l) {
  int n = 1;
  for(int i = 0; i < l; i++) n *= 2;
  for(int i = 0; i < po_N; i = i + n) {
	for(int j = 0; j < po_N; j = j + n) p2_sub(i, j, n);
  }
  map_flush();
}

void p3(int l) {
  int n = 1;
  for(int i = 0; i < l; i++) n *= 2;
  for(int i = 0; i < po_N; i = i + n) {
	for(int j = 0; j < po_N; j = j + n) p3_sub(i, j, n);
  }
  map_flush();
}

void p4(int l) {
  int n = 1;
  for(int i = 0; i < l; i++) n *= 2;
  for(int i = 0; i < po_N; i = i + n) {
	for(int j = 0; j < po_N; j = j + n) p4_sub(i, j, n);
  }
  map_flush();
}

void map_move(int r, int c, int nr, int nc, int n) {
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) tmp_map[nr + i][nc + j] = _map[r + i][c + j];
  }
}

void p5(int l) {
  int n = 1;
  for(int i = 0; i < l; i++) n *= 2;
  for(int i = 0; i < po_N; i = i + n) {
	for(int j = 0; j < po_N; j = j + n) map_move(i, j, po_N - n - i, j, n);
  }
  map_flush();
}

void p6(int l) {
  int n = 1;
  for(int i = 0; i < l; i++) n *= 2;
  for(int i = 0; i < po_N; i = i + n) {
	for(int j = 0; j < po_N; j = j + n) map_move(i, j, i, po_N - n - j, n);
  }
  map_flush();
}

void p7(int l) {
  int n = 1;
  for(int i = 0; i < l; i++) n *= 2;
  for(int i = 0; i < po_N; i = i + n) {
	for(int j = 0; j < po_N; j = j + n) map_move(i, j, j, po_N - n - i, n);
  }
  map_flush();
}

void p8(int l) {
  int n = 1;
  for(int i = 0; i < l; i++) n *= 2;
  for(int i = 0; i < po_N; i = i + n) {
	for(int j = 0; j < po_N; j = j + n) map_move(i, j, po_N - n - j, i, n);
  }
  map_flush();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> R;
  
  po_N = 1;
  for(int i = 0; i < N; i++) po_N *= 2;
  for(int i = 0; i < po_N; i++) {
	for(int j = 0; j < po_N; j++) cin >> _map[i][j];
  }
  
  for(int i = 0; i < R; i++) cin >> input[i].first >> input[i].second;
  
  for(int i = 0; i < R; i++) {
	if(input[i].first == 1) p1(input[i].second);
	if(input[i].first == 2) p2(input[i].second);
	if(input[i].first == 3) p3(input[i].second);
	if(input[i].first == 4) p4(input[i].second);
	if(input[i].first == 5) p5(input[i].second);
	if(input[i].first == 6) p6(input[i].second);
	if(input[i].first == 7) p7(input[i].second);
	if(input[i].first == 8) p8(input[i].second);
  }

  for(int i = 0; i < po_N; i++) {
	for(int j = 0; j < po_N; j++) cout << _map[i][j] << " ";
	cout << "\n";
  }
  cout << "\n";
  return 0;
}
