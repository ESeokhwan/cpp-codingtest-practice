#include <bits/stdc++.h>
using namespace std;

int n, m;
int indeg[32000];
vector<int> nts[32000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(indeg, 0, sizeof(indeg));

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
	int input1, input2;
	cin >> input1 >> input2;
	indeg[input2 - 1]++;
	nts[input1 - 1].push_back(input2 - 1);
  }

  priority_queue<int, vector<int>, greater<int> > q;
  for(int i = 0; i < n; i++) {
	if(indeg[i] == 0) q.push(i);
  }

  while(!q.empty()) {
	int cur = q.top();
	cout << cur + 1<< " ";
	q.pop();

	for(int i = 0; i < nts[cur].size(); i++) {
	  if(--indeg[nts[cur][i]] == 0) q.push(nts[cur][i]);
	}
  }

  cout << "\n";
  return 0;
}
