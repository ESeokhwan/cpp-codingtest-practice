#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> graph[10005];
bool reach[10005];
int result[10005];
int a, b;

void init_result() {
  for(int i = 0; i < n; i++) {
	result[i] = 0;
  }
}

void init_reach() {
  for(int i = 0; i < n; i++) {
	reach[i] = false;
  }
}

void traverse(int sp) {
  queue<int> que;
  int cp;
  int tp;
  init_reach();
  reach[sp] = true;

  que.push(sp);
  while(!que.empty()) { // NOT
	cp = que.front();
	que.pop();
    for(int i = 0; i < graph[cp].size(); i++) {
	  tp = graph[cp][i];
	  if(!reach[tp]) { // NOT
		que.push(tp);
		result[sp]++;
		reach[tp] = true;
	  }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m; 
  init_result();

  for(int i = 0; i < m; i++) {
	cin >> a >> b;
	graph[b-1].push_back(a-1);
  }

  for(int i = 0; i < n; i++) {
	traverse(i);	
  }

  int total_max = 0;
  int local_max = 0;

  int last_max_idx = -1;
  int local_max_idx = -1;

  for(int i = 0; i < n; i++) {
	local_max = 0;
	for(int j = last_max_idx + 1; j < n; j++) {
	  if(result[j] > local_max) {
		local_max = result[j];
		local_max_idx = j;
	  }
	}

	if(i == 0) {
	  if(local_max == 0) break;
	  total_max = local_max;
	}
	
	if(total_max != local_max) break;
	last_max_idx = local_max_idx;
	cout << last_max_idx + 1 << " ";
  }

  cout << "\n";
  return 0;
}
