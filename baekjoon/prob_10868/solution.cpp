#include <bits/stdc++.h>
using namespace std;

int n, m;
int nums[100000];
pair<int, int> probs[100000];
pair<int, int> ranges[100000];

int tree[200000];

int init_tree_rec(int rt, int st_idx, int en_idx) {
  if(st_idx == en_idx) {
	tree[rt] = nums[st_idx];
	return tree[rt];
  }
  int new_range_size = (en_idx - st_idx) / 2;
  tree[rt] = min(
	  init_tree_rec((rt + 1) * 2 - 1, st_idx, st_idx + new_range_size),
	  init_tree_rec((rt + 1) * 2, st_idx + new_range_size + 1, en_idx)
  );
  return tree[rt];
}

void init_tree() {
  init_tree_rec(0, 0, n - 1);
}

int test_rec(int rt, int st_idx, int en_idx, int a, int b) {
  if(st_idx == a && en_idx == b) {
	return tree[rt];
  } 

  int new_range_size = (en_idx - st_idx) / 2;
  if(st_idx + new_range_size < a) {
	return test_rec((rt + 1) * 2, st_idx + new_range_size + 1, en_idx, a, b);
  }
  if(st_idx + new_range_size + 1 > b) {
	return test_rec((rt + 1) * 2 - 1, st_idx, st_idx + new_range_size, a, b);
  }
  return min(
	  test_rec(
		(rt + 1) * 2 - 1, st_idx, st_idx + new_range_size, 
		a, st_idx + new_range_size
	  ),
	  test_rec(
		(rt + 1) * 2, st_idx + new_range_size + 1, en_idx,
		st_idx + new_range_size + 1, b
	  )
  );
}

int test(int a, int b) {
  return test_rec(0, 0, n - 1, a, b);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> nums[i];
  for(int i = 0; i < m; i++) cin >> probs[i].first >> probs[i].second;
  
  init_tree();
  for(int i = 0; i < m; i++) {
	cout << test(probs[i].first - 1, probs[i].second - 1) << "\n";
  }
  return 0;
}
