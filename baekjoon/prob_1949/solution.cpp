#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> town_rel[10000];
int town_pop[10000];
int visited[10000];
int dp[10000][3];

int gofd(int root, int irgt) {
  if(dp[root][irgt] != -1) {
	return dp[root][irgt];
  }
  
  visited[root] = true;
  dp[root][irgt] = 0;
  if(irgt == 0) { // root_is_good
	dp[root][irgt] += town_pop[root];
	for(int i = 0; i < town_rel[root].size(); i++) {
	  if(visited[town_rel[root][i]]) continue;
	  dp[root][irgt] += max(gofd(town_rel[root][i], 1), gofd(town_rel[root][i], 2));
	}
  } else if(irgt == 1) { // root is not good and at least one child is good
	int min_diff = -1;
	bool cant = true;
	bool no_child = true;
	for(int i = 0; i < town_rel[root].size(); i++) {
	  if(visited[town_rel[root][i]]) continue;
	  no_child = false;
	  int tmp1 = gofd(town_rel[root][i], 0);
	  int tmp2 = gofd(town_rel[root][i], 1);
	  if(tmp1 < tmp2) {
		dp[root][irgt] += tmp2;
		if(min_diff == -1 || min_diff > tmp2 - tmp1) {
		  min_diff = tmp2 - tmp1;
		}
	  } else {
		dp[root][irgt] += tmp1;
		cant = false;
	  }
	}
	if(!no_child && cant) dp[root][irgt] -= min_diff;
  } else { // root is not good and all children are not good
	for(int i = 0; i < town_rel[root].size(); i++) {
	  if(visited[town_rel[root][i]]) continue;
	  dp[root][irgt] += gofd(town_rel[root][i], 1);
	}
  }
	
  visited[root] = false;
  return dp[root][irgt];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(dp, -1, sizeof(dp));
  memset(visited, false, sizeof(visited));

  cin >> n;
  for(int i = 0; i < n; i++) cin >> town_pop[i];
  for(int i = 0; i < n - 1; i++) {
	int a, b;
	cin >> a >> b;
	town_rel[a - 1].push_back(b - 1);
	town_rel[b - 1].push_back(a - 1);
  }

  cout << max(gofd(0, 0), gofd(0, 1)) << "\n";
  return 0;
}
