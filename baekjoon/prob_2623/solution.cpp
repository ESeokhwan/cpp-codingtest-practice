#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<pair<int, int> > teams[1000];
pair<int, vector<int> > pds[100];
vector<int> res;

queue<int> q;
bool is_on_q[1000];

void push_first() {
  for(int i = 0; i < n; i++) {
	if(is_on_q[i]) continue;
	if(teams[i].size() == 0) {
	  q.push(i);
	  is_on_q[i] = true;
	  continue;
	}
	
	bool is_all_first = true;
	for(int j = 0; j < teams[i].size(); j++) {
	  if(teams[i][j].second > pds[teams[i][j].first].first) {
		is_all_first = false;
		break;
	  }
	}
	if(is_all_first) {
	  q.push(i);
	  is_on_q[i] = true;
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(is_on_q, false, sizeof(is_on_q));
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
	int cnt;
	cin >> cnt;
	pds[i].first = 0;
	for(int j = 0; j < cnt; j++) {
	  int input;
	  cin >> input;
	  pds[i].second.push_back(input - 1);
	  teams[input-1].push_back(make_pair(i, j));
	}
  }

  push_first();
  while(!q.empty()) {
	int cur = q.front();
	q.pop();
	res.push_back(cur);

	for(int i = 0; i < m; i++) {
	  if(pds[i].second.size() <= pds[i].first) continue;
	  if(pds[i].second[pds[i].first] != cur) continue;
	  pds[i].first++;
	}
	push_first();
  }

  if(res.size() < n) cout << "0\n";
  else {
	for(int i = 0; i < res.size(); i++) cout << res[i] + 1 << " ";
	cout << "\n";
  }
  return 0;
}
