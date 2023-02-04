#include <bits/stdc++.h>

using namespace std;

int N, g_min;

bool is_back[20][20];

void flip_row(int r) {
  for(int i = 0; i < N; i++) {
	is_back[r][i] = !is_back[r][i];
  }
}

void update_g_min() {
  int local_min = 0;
  for(int i = 0; i < N; i++) {
	int tmp = 0;
	for(int j = 0; j < N; j++) {
	  if(is_back[j][i]) tmp++;
	}
	if(tmp > N/2) tmp = N - tmp;
	local_min += tmp;
  }
  if(local_min < g_min) g_min = local_min;
}


void rec(int cnt) {
  if(cnt == N) {
	return;
  }

  update_g_min();
  rec(cnt+1);
  flip_row(cnt);
  update_g_min();
  rec(cnt+1);
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 0; i < 20; i++) {
	memset(is_back[i], false, sizeof(bool)*20);
  }

  g_min = 900000;

  cin >> N;

  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  char input;
	  cin >> input;
	  if(input =='T') is_back[i][j] = true;
	}
  }

  rec(0);
  cout<< g_min << "\n";

  cout << "\n";
  return 0;
}
