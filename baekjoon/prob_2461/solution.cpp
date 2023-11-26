#include <bits/stdc++.h>
using namespace std;

int INF = 1100000000;

int n, m;
vector<int> classes[1000];

int get_min_diff() {
  priority_queue<pair<int, int> > pq;
  int min_diff = INF;
  for(int i = 0; i < m; i++) {
	while(!pq.empty()) pq.pop();
	for(int j = 1; j < n; j++) {
	  int basis = classes[0][i];
	  int idx = 
		lower_bound(classes[j].begin(), classes[j].end(), basis) - classes[j].begin();
	  int lower_diff, upper_diff;
	  if(idx == m) {
		lower_diff = basis - classes[j][idx-1];
		upper_diff = INF;
	  } else if(classes[j][idx] == basis) {
		lower_diff = 0;
		upper_diff = 0;
	  } else if(idx == 0) {
		lower_diff = INF;
		upper_diff = classes[j][idx] - basis;
	  } else {
		lower_diff = basis - classes[j][idx-1];
		upper_diff = classes[j][idx] - basis;
	  }
	  pq.push({upper_diff, lower_diff});
	}
	
	int prev_upper_diff = -1;
	int cur_lower_diff = 0;
	int cur_diff = -1;
	while(!pq.empty()) {
	  int upper_diff = pq.top().first;
	  int lower_diff = pq.top().second;
	  pq.pop();
	  
	  if(cur_diff == -1) {
		cur_diff = upper_diff;
		cur_lower_diff = lower_diff;
		continue;
	  }
	  cur_diff = min(cur_diff, cur_lower_diff + upper_diff);
	  cur_lower_diff = max(cur_lower_diff, lower_diff); 
	}
	cur_diff = min(cur_diff, cur_lower_diff);
	min_diff = min(min_diff, cur_diff);
  }
  return min_diff;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	  int input;
	  cin >> input;
	  classes[i].push_back(input);
	}
	sort(classes[i].begin(), classes[i].end());
  }

  cout << get_min_diff() << "\n";
  return 0;
}
