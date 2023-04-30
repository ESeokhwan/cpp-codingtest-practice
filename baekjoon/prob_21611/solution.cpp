#include <bits/stdc++.h>
using namespace std;

int n, m, res;
int _map[49][49];
int beads[2500];

int bs[100];
int bd[100];

pair<int, int> offsets[4] = {
  make_pair(-1, 0),
  make_pair(1, 0),
  make_pair(0, -1),
  make_pair(0, 1)
};

int get_idx(int r, int c) {
  int cr = (n + 1) / 2 - 1;
  int cc = (n + 1) / 2 - 1;

  int cnt = 0;
  if(r == cr && c == cc) return 0;
  for(int i = 1; i <= n; i++) {
	for(int j = 0; j < i; j++) {
	  cnt++;
	  int v = 1;
	  if(i % 2 == 1) v = -1;
	  cc += v;
	  if(r == cr && c == cc) return cnt;
	}
	for(int j = 0; j < i; j++) {
	  cnt++;
	  int v = 1;
	  if(i % 2 == 0) v = -1;
	  cr += v;
	  if(r == cr && c == cc) return cnt;
	}
  }
}

void init_beads() {
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) beads[get_idx(i, j)] = _map[i][j];
  }
}

void blizard(int d, int s) {
  int sr = (n + 1) / 2 - 1;
  int sc = (n + 1) / 2 - 1;
  for(int i = 1; i <= s; i++) {
	beads[get_idx(sr + i * offsets[d].first, sc + i * offsets[d].second)] = 0;
  }
}

void move() {
  int new_idx = 1;
  for(int i = 1; i < n * n; i++) {
	if(beads[i] == 0) continue;
	beads[new_idx++] = beads[i];
  }

  for(int i = new_idx; i < n * n; i++) beads[i] = 0;
}

bool boom() {
  bool boomed = false;
 
  int cnt = 0;
  int prev = 0;
  int last_idx = 0;
  for(int i = 1; i < n * n; i++) {
	if(beads[i] == 0) continue;
	last_idx = i;
	
	if(prev == 0) prev = beads[i];
	if(prev == beads[i]) {
	  cnt += 1;
	} else {
	  if(cnt >= 4) {
		memset(beads + (i - cnt), 0, sizeof(int) * cnt);
		res += (cnt * prev);
		boomed = true;
	  }
	  cnt = 1;
	}
	prev = beads[i];
  }
  if(cnt >= 4) {
	memset(beads + (last_idx + 1 - cnt), 0, sizeof(int) * cnt);
	res += (cnt * prev);
	boomed = true;
  }
  return boomed;
}

void reload_beads() {
  vector<int> new_beads(1, 0);
  int cnt = 0;
  int prev = 0;
  for(int i = 1; i < n * n; i++) {
	if(beads[i] == 0) break;
	
	if(prev == 0) prev = beads[i];
	if(prev == beads[i]) {
	  cnt += 1;
	} else {
	  new_beads.push_back(cnt);
	  new_beads.push_back(prev);
	  cnt = 1;
	}
	prev = beads[i];
  }
  if(cnt != 0) {
	new_beads.push_back(cnt);
	new_beads.push_back(prev);
  }
  
  for(int i = 0; i < n * n; i++) {
	if(i >= new_beads.size()) beads[i] = 0;
	else beads[i] = new_beads[i];
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  cin >> _map[i][j];
	}
  }
  for(int i = 0;i < m; i++) {
	int input;
	cin >> input >> bs[i];
	bd[i] = input - 1;
  }
  init_beads();

  res = 0;
  for(int i = 0; i < m; i++) {
	blizard(bd[i], bs[i]);
	move();
	while(boom()) {
	  move();
	}
	reload_beads();
  }

  cout << res << "\n";
  return 0;
}
