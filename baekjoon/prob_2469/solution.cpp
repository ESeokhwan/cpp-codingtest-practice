#include <bits/stdc++.h>
using namespace std;

int n;
int k;

char _map[1000][26];
vector<int> init_state;
vector<int> result_state; 

int hidden_line_num;
vector<char> hidden_line;


vector<int> ladder_down(int st, int en, vector<int>& sp_state) {
  int flag = 1;
  if (st > en) {
	flag = -1;
  }
  
  vector<int> cur_state;
  cur_state.assign(k, -1);
  for (int i = 0; i < k; i++) {
	cur_state[i] = sp_state[i];
  }

  for (int i = st; flag * i < en * flag; i += flag) {
	for (int j = 0; j < k - 1; j++) {
	  if (_map[i][j] == '-') {
		int tmp = cur_state[j];
		cur_state[j] = cur_state[j + 1];
		cur_state[j + 1] = tmp;
	  }
	}
  }
  return cur_state;
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> k >> n;
  for (int i = 0; i < k; i++) {
	char input;
	cin >> input;
	result_state.push_back(input - 'A');
	init_state.push_back(i);
  }

  for (int i = 0; i < n; i++) {
	for (int j = 0; j < k - 1; j++) {
	  cin >> _map[i][j];
	  if (_map[i][j] == '?') hidden_line_num = i;
	}
  }

  vector<int> prev_hidden = ladder_down(0, hidden_line_num, init_state);
  vector<int> after_hidden = ladder_down(n - 1, hidden_line_num, result_state);

  bool is_failed = false;
  for (int i = 0; i < k - 1; i++) {
	if (prev_hidden[i] == after_hidden[i] || (i != 0 && prev_hidden[i] == after_hidden[i - 1])) {
	  hidden_line.push_back('*');
	} else if (prev_hidden[i] == after_hidden[i + 1]) {
	  hidden_line.push_back('-');
	} else {
	  is_failed = true;
	}
  }

  for (int i = 0; i < k - 1; i++) {
	if (is_failed) cout << "x";
	else cout << hidden_line[i];
  }
  cout << "\n";
  return 0;
}
