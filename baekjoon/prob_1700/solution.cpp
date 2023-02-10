#include <bits/stdc++.h>
using namespace std;

int N, K;

bool is_connected[110];

vector< pair< int, int > > mult_status;

int schedule[100];

/*
void rec(int cnt, int acc) {
  if(cnt == K) {
	res = min(res, acc);
  }
  
  int next_item = schedule[cnt];
  if(is_connected[next_item]) {
	rec(cnt+1, acc);
  } else if(mult_cnt < N) {
	is_connected[next_item] = true;
	mult_cnt++;
	mult_status.insert(next_item);
	rec(cnt+1, acc);
  } else {
	for(set<int>::iterator it=mult_status.begin(); it!=mult_status.end(); ++it) {
	  int removed = *(it);

	is_connected[next_item] = true;
  }
}
*/

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;

  for(int i = 0; i < K; i++) {
	cin >> schedule[i];
  }

  int res = 0;
  for(int i = 0; i < K; i++) {
	int next_item = schedule[i];
	if(is_connected[next_item]) continue;
	if(mult_status.size() < N) {
	  is_connected[next_item] = true;
	  mult_status.push_back(make_pair(next_item, 0));
	  continue;
	}

	res++;
	for(int j = 0; j < N; j++) mult_status[j].second = 999999;
	
	for(int j = i+1; j < K; j++) {
	  for(int l = 0; l < N; l++) {
		if(schedule[j] == mult_status[l].first && j < mult_status[l].second) {
		  mult_status[l].second = j;
		}
	  }
	}
	
	int l_max = mult_status[0].second;
	int far_idx = 0;
	for(int j = 1; j < N; j++) {
	  if(mult_status[j].second > l_max) {
		far_idx = j;
		l_max = mult_status[j].second;
	  }
	}

	is_connected[mult_status[far_idx].first] = false;
	mult_status[far_idx].first = next_item;
	is_connected[next_item] = true;
  }

  cout << res << "\n";
  cout << "\n";
  return 0;
}
