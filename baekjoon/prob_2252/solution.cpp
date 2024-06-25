#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> after_i[32005];
int indeg[32005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(indeg, 0, sizeof(indeg));

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
	int input1, input2;
	cin >> input1 >> input2;
	indeg[input2] += 1;
	after_i[input1].push_back(input2);
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) {
	if (indeg[i] != 0) continue;
	q.push(i);
  }
  
  while (!q.empty()) {
	int cur = q.front();
	cout << cur << " ";
	q.pop();

	for (auto next_p: after_i[cur]) {
	  indeg[next_p] -= 1;
	  if (indeg[next_p] == 0) {
		q.push(next_p);
	  }
	}
  }

  cout << "\n";
  return 0;
}
