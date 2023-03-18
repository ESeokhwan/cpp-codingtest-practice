#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[100000][5];
int init_nums[1024][1024];

int bt[1024][1024];
int bt_r[1024][1024];

void set_bt_r() {
  int accs[1024][15];
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  int tmp = n;
	  int cnt = 0;
	  while(tmp != 0) {
		accs[i][cnt] += init_nums[i][j];
		tmp = tmp >> 1;
		cnt++;
	  }

	  tmp = j;
	  cnt = 0;
	  while(tmp % 2 != 0) {
		accs[i][cnt] = 0;
		tmp = tmp >> 1;
		cnt++;
	  }
	  bt_r[i][j] = accs[i][cnt];
	}
  }
}

void set_bt_c() {
  int accs[1024][15];
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  int tmp = n;
	  int cnt = 0;
	  while(tmp != 0) {
		accs[i][cnt] += bt_r[j][i];
		tmp = tmp >> 1;
		cnt++;
	  }

	  tmp = j;
	  cnt = 0;
	  while(tmp % 2 != 0) {
		accs[i][cnt] = 0;
		tmp = tmp >> 1;
		cnt++;
	  }
	  bt[j][i] = accs[i][cnt];
	}
  }
}

void set_bt() {
  set_bt_r();
  set_bt_c();
}

int get_sum(int r, int c) {
  if(r < 0 || c < 0) return 0;
  int res = 0;
  int i = r + 1;
  while(i >= 1) {
	int j = c + 1;
	while(j >= 1) {
	  res += bt[i - 1][j - 1];
	  j -= j&(-j);
	}
	i -= i&(-i);
  }
  return res;
}

int get_sum(int r1, int c1, int r2, int c2) {
  return get_sum(r2, c2) - (get_sum(r2, c1 - 1) + get_sum(r1 - 1, c2)) + get_sum(r1 - 1, c1 - 1);
}

void update(int r, int c, int new_val) {
  int old_val = init_nums[r][c];
  int offset = new_val - old_val;

  int i = r + 1;
  while(i <= n) {
	int j = c + 1;
	while(j <= n) {
	  bt[i - 1][j - 1] += offset;
	  j += j&(-j);
	}
	i += i&(-i);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  cin >> init_nums[i][j];
	}
  }
  for(int i = 0; i < m; i++) {
	cin >> input[i][0];
	if(input[i][0] == 0) cin >> input[i][1] >> input[i][2] >> input[i][3];
	if(input[i][0] == 1) cin >> input[i][1] >> input[i][2] >> input[i][3] >> input[i][4];
  }

  set_bt();

  for(int i = 0; i < m; i++) {
	if(input[i][0] == 0) update(input[i][1] - 1, input[i][2] - 1, input[i][3]);
	if(input[i][0] == 1) cout << get_sum(input[i][1] - 1, input[i][2] - 1, input[i][3] - 1, input[i][4] - 1) << "\n";
  }
  cout << "\n";
  return 0;
}
