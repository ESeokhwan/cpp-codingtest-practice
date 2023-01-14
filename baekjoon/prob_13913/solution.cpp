#include <bits/stdc++.h>
using namespace std;

int N, K;
int min_tick;

vector< int > min_path;

vector< int > cur_pos_list[2];
bitset<1000000> reached;
bool is_end;

void recursion(int acc, vector< int > path) {
  int cur_pos = *(path.end() - 1);
  vector< int > new_path = path;
  
  if(acc > min_tick) {
	return;
  } else if(cur_pos == N) {
	min_path = path;
	min_tick = -1;
  } else if(cur_pos < N) {
	for(int i = cur_pos; i < N; i++) {
	  new_path.push_back(i+1);
	}
	recursion(acc+N-cur_pos, new_path);
  } else if(cur_pos % 2 == 1) {
	new_path.push_back(cur_pos - 1);
	recursion(acc+1, new_path);

	new_path = path;
	new_path.push_back(cur_pos + 1);
	recursion(acc+1, new_path);
  } else if(cur_pos >=  2 * N) {
	new_path.push_back(cur_pos / 2);
	recursion(acc+1, new_path);
  } else if(cur_pos - N > N - cur_pos / 2) {
	new_path.push_back(cur_pos / 2);
	recursion(acc+1, new_path);
  } else {
	for(int i = cur_pos; i > N; i--) {
	  new_path.push_back(i-1);
	}
	recursion(acc+cur_pos-N, new_path);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;

  is_end = false;
  reached.reset();
  cur_pos_list[0].push_back(K);

  for(min_tick = 0; true; min_tick++) {
	int c_arr = min_tick % 2;
	int n_arr = (min_tick + 1) % 2;
	cur_pos_list[n_arr].clear();

	for(int cur_pos : cur_pos_list[c_arr]) {
	  if(cur_pos == N) {
		is_end = true;
		break;
	  } else if(reached.test(cur_pos)) {
		continue;
	  } else if(cur_pos < N) {
		cur_pos_list[n_arr].push_back(cur_pos+1);
	  } else if(cur_pos % 2 == 1) {
		cur_pos_list[n_arr].push_back(cur_pos + 1);
		cur_pos_list[n_arr].push_back(cur_pos - 1);
	  } else if(cur_pos >=  2 * N) {
		cur_pos_list[n_arr].push_back(cur_pos / 2);
	  } else if(cur_pos - N > N - cur_pos / 2) {
		cur_pos_list[n_arr].push_back(cur_pos / 2);
	  } else {
		cur_pos_list[n_arr].push_back(cur_pos - 1);
	  }
	  reached.set(cur_pos);
	}
	if(is_end) break;
  }

  cout << min_tick << "\n";
  
  vector< int > path;
  path.push_back(K);
  recursion(0, path);

  for(int i = min_path.size()-1; i >= 0; i--) {
	cout << min_path[i] << " ";
  }

  cout << "\n";
  return 0;
}

