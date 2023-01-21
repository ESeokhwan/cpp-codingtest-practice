#include <bits/stdc++.h>
using namespace std;

int N, M;
int res;

int paper[500][500];
int tmp_paper[500][500];
int edited_paper[500][500];

int tmp_N, tmp_M;
int edited_N, edited_M;

pair< int, int > tet[5][4] = {
  {
	make_pair(0, 0),
	make_pair(0, 1),
	make_pair(0, 2),
	make_pair(0, 3)
  },
  {
	make_pair(0, 0),
	make_pair(0, 1),
	make_pair(1, 0),
	make_pair(1, 1)
  },
  {
	make_pair(0, 0),
	make_pair(1, 0),
	make_pair(2, 0),
	make_pair(2, 1)
  },
  {
	make_pair(0, 0),
	make_pair(1, 0),
	make_pair(1, 1),
	make_pair(2, 1)
  },
  {
	make_pair(0, 0),
	make_pair(0, 1),
	make_pair(0, 2),
	make_pair(1, 1)
  }
};

bool edit[8][3] = {
  {0, 0, 0},
  {0, 0, 1},
  {0, 1, 0},
  {0, 1, 1},
  {1, 0, 0},
  {1, 0, 1},
  {1, 1, 0},
  {1, 1, 1}
};

void init() {
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < M; j++) {
	  tmp_paper[i][j] = paper[i][j];
	  edited_paper[i][j] = paper[i][j];
	}
  }
  tmp_N = N;
  tmp_M = M;
  edited_N = tmp_N;
  edited_M = tmp_M;
}

void transpose() {
  for(int i = 0; i < tmp_N; i++) {
	for(int j = 0; j < tmp_M; j++) {
	  edited_paper[j][i] = tmp_paper[i][j];
	}
  }
  edited_N = tmp_M;
  edited_M = tmp_N;
  for(int i = 0; i < edited_N; i++) {
	for(int j = 0; j < edited_M; j++) {
	  tmp_paper[i][j] = edited_paper[i][j];
	}
  }
  tmp_N = edited_N;
  tmp_M = edited_M;
}

void v_flip() {
  for(int i = 0; i < tmp_N; i++) {
	for(int j = 0; j < tmp_M; j++) {
	  edited_paper[i][j] = tmp_paper[i][tmp_M-1-j];
	}
  }
  for(int i = 0; i < edited_N; i++) {
	for(int j = 0; j < edited_M; j++) {
	  tmp_paper[i][j] = edited_paper[i][j];
	}
  }
}

void h_flip() {
  for(int i = 0; i < tmp_N; i++) {
	for(int j = 0; j < tmp_M; j++) {
	  edited_paper[i][j] = tmp_paper[tmp_N-1-i][j];
	}
  }
  for(int i = 0; i < edited_N; i++) {
	for(int j = 0; j < edited_M; j++) {
	  tmp_paper[i][j] = edited_paper[i][j];
	}
  }
}

int calc_sum(int tet_num, int st_r, int st_c) {
  int sum, tmp_r, tmp_c;
  sum = 0;
  for(int i=0; i<4; i++) {
	tmp_r = tet[tet_num][i].first + st_r;
	tmp_c = tet[tet_num][i].second + st_c;
	if(tmp_r >= edited_N || tmp_c >= edited_M) return 0;
	sum += edited_paper[tmp_r][tmp_c];
  }
  return sum;
}

void calc_max() {
  int tmp_max;
  for(int i = 0; i < edited_N; i++) {
	for(int j = 0; j < edited_M; j++) {
	  for(int k = 0; k < 5; k++) {
		tmp_max = calc_sum(k, i, j);
		if(tmp_max > res) res = tmp_max;
	  }
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  res = 0;
  cin >> N >> M;
  int num;
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < M; j++) {
	  cin >> paper[i][j];
	}
  }

  for(int i = 0; i < 8; i++) {
	init();
	if(edit[i][0]) transpose();
	if(edit[i][1]) v_flip();
	if(edit[i][2]) h_flip();

	calc_max();
  }

  cout << res << "\n";
  cout << "\n";
  return 0;
}

