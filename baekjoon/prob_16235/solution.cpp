#include <bits/stdc++.h>
using namespace std;

int N, M, K;

deque<int> tree[10][10];
int A[10][10];
int cur_vit[10][10];

int near_offset[8][2] = {
  {-1, -1},
  {-1, 0},
  {-1, 1},
  {0, -1},
  {0, 1},
  {1, -1},
  {1, 0},
  {1, 1}
};

void born_new_tree(int src_r, int src_c) {
  for(int i = 0; i < 8; i++) {
	int new_r = src_r + near_offset[i][0];
	int new_c = src_c + near_offset[i][1];
	if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= N) continue;
	tree[new_r][new_c].push_front(1);
  }
}

void spring_summer() {
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  int death_tree_cnt = tree[i][j].size();
	  for(int k = 0; k < tree[i][j].size(); k++) {
		if(cur_vit[i][j] < tree[i][j][k]) {
		  break;
		}
		cur_vit[i][j] -= tree[i][j][k];
		tree[i][j][k] += 1 ;
		death_tree_cnt--;
	  }
	  for(int k = 0; k < death_tree_cnt; k++) {
		cur_vit[i][j] += (tree[i][j].back() / 2);
		tree[i][j].pop_back();
	  }
	}
  }
}

void fall() {
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  for(int k = 0; k < tree[i][j].size(); k++) {
		if(tree[i][j][k] % 5 == 0) {
		  born_new_tree(i, j);
		}
	  }
	}
  }
}

void winter() {
  for(int i=0; i < N; i++) {
	for(int j=0; j < N; j++) {
	  cur_vit[i][j] += A[i][j];
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> K;

  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  cin >> A[i][j];
	}
  }

  for(int i = 0; i < M; i++) {
	int x, y, z;
	cin >> x >> y >> z;
	tree[x-1][y-1].push_back(z);
  }

  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  cur_vit[i][j] = 5;
	}
  }

  for(int i = 0; i < K; i++) {
	spring_summer();
	fall();
	winter();
  }

  int tree_cnt = 0;
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  tree_cnt += tree[i][j].size();
	}
  }


  cout << tree_cnt << "\n";
  cout << "\n";
  return 0;
}
