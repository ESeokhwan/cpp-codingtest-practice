#include <bits/stdc++.h>
using namespace std;

typedef struct Fb {
  Fb(const Fb &oth) {
	this -> mess = oth.mess;
	this -> speed = oth.speed;
	this -> dir = oth.dir;
  }

  Fb(int mess, int speed, int dir) {
	this -> mess = mess;
	this ->speed = speed;
	this -> dir = dir;
  }

  int mess;
  int speed;
  int dir;
} Fb;

pair<int, int> dirs[8] = {
  make_pair(-1, 0),
  make_pair(-1, 1),
  make_pair(0, 1),
  make_pair(1, 1),
  make_pair(1, 0),
  make_pair(1, -1),
  make_pair(0, -1),
  make_pair(-1, -1)
};

int n, m, k;
vector<Fb> fbs[50][50];
vector<Fb> n_fbs[50][50];

void move() {
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) n_fbs[i][j].clear();
  }

  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  for(Fb fb: fbs[i][j]) {
		int nr, nc;
		nr = (i + dirs[fb.dir].first * fb.speed) % n;
		nc = (j + dirs[fb.dir].second * fb.speed) % n;
		nr = (nr < 0) ? nr + n : nr;
		nc = (nc < 0) ? nc + n : nc;
		n_fbs[nr][nc].push_back(Fb(fb.mess, fb.speed, fb.dir));
	  }
	}
  }

  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) fbs[i][j].clear();
  }

  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  if(n_fbs[i][j].size() == 0) continue;
	  if(n_fbs[i][j].size() == 1) {
		fbs[i][j].push_back(Fb(n_fbs[i][j][0]));
		continue;
	  }
	  
	  int n_mess = 0;
	  int n_speed = 0;
	  int prev_dir = -1;
	  bool all_dsame = true;
	  for(Fb fb: n_fbs[i][j]) {
		n_mess += fb.mess;
		n_speed += fb.speed;

		if(prev_dir != -1 && all_dsame && (prev_dir + fb.dir) % 2 != 0) all_dsame = false;
		prev_dir = fb.dir;
	  }

	  n_mess = (n_mess / 5);
	  n_speed = (n_speed / n_fbs[i][j].size());

	  if(n_mess == 0) continue;
	  if(all_dsame) {
		fbs[i][j].push_back(Fb(n_mess, n_speed, 0));
		fbs[i][j].push_back(Fb(n_mess, n_speed, 2));
		fbs[i][j].push_back(Fb(n_mess, n_speed, 4));
		fbs[i][j].push_back(Fb(n_mess, n_speed, 6));
	  } else {
		fbs[i][j].push_back(Fb(n_mess, n_speed, 1));
		fbs[i][j].push_back(Fb(n_mess, n_speed, 3));
		fbs[i][j].push_back(Fb(n_mess, n_speed, 5));
		fbs[i][j].push_back(Fb(n_mess, n_speed, 7));
	  }
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
	int ir, ic, imess , idir, ispeed;
	cin >> ir >> ic >> imess >> ispeed >> idir;
	fbs[ir - 1][ic - 1].push_back(Fb(imess, ispeed, idir));
  }

  for(int i = 0; i < k; i++) {
	move();
  }


  int res = 0;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  for(Fb fb: fbs[i][j]) {
		res += fb.mess;
	  }
	}
  }

  cout << res << "\n";
  return 0;
}
