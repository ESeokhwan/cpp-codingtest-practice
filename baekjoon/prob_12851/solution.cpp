#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> n_sec_after[2];
int cur_pos, tick, cnt;
bool is_end;
bitset<100005> is_checked;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;

  is_end = false;
  tick = 0;
  cnt = 0;
  is_checked.reset();
  n_sec_after[0].push_back(K);
  for(int i = 0; true; i++) {
	n_sec_after[(i+1)%2].clear();
	for(int j = 0; j < n_sec_after[i%2].size(); j++) {
	  cur_pos = n_sec_after[i%2][j];
	  if(is_checked.test(cur_pos)) continue;

	  if(cur_pos == N) {
		cnt++;
		is_end = true;
	  }
	  if(is_end) continue;

	  if(cur_pos < N) {
		n_sec_after[(i+1)%2].push_back(cur_pos + 1);
		continue;
	  }
	 
	  if(cur_pos % 2 == 1) {
		n_sec_after[(i+1)%2].push_back(cur_pos - 1);
		n_sec_after[(i+1)%2].push_back(cur_pos + 1);
		continue;
	  }

	  if(cur_pos / 2 > N) {
		if(cur_pos / 2 == cur_pos - 1) 
		  n_sec_after[(i+1)%2].push_back(cur_pos - 1);
    	n_sec_after[(i+1)%2].push_back(cur_pos / 2);
		continue;
	  }


	  if(cur_pos - N == N - (cur_pos / 2) + 1) {
    	n_sec_after[(i+1)%2].push_back(cur_pos / 2);
    	n_sec_after[(i+1)%2].push_back(cur_pos - 1);
	  } else if(cur_pos - N > N - (cur_pos / 2) + 1) {
    	n_sec_after[(i+1)%2].push_back(cur_pos / 2);
	  } else {
		n_sec_after[(i+1)%2].push_back(cur_pos - 1);
	  }
	}
	
	if(is_end) {
	  tick = i;
	  break;
	}
	
	for(int j = 0; j < n_sec_after[i%2].size(); j++) {
	  cur_pos = n_sec_after[i%2][j];
	  is_checked[cur_pos] = true;
	}
  }

  cout << tick << "\n" << cnt;
  cout << "\n";
  return 0;
}
