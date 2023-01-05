#include <bits/stdc++.h>

using namespace std;

int N, parent, rm_idx, root_idx, cn;
int cnt = 0;
vector<int> children[55];
bool dirty[55];
stack<int> st;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for(int i = 0; i < N; i++) {
	dirty[i] = false;
	cin >> parent;
	if(parent == -1) {
	  root_idx = i;
	  continue;
	}
	children[parent].push_back(i);
  }
  cin >> rm_idx;

  st.push(root_idx);
  while(!st.empty()) {
	cn = st.top();
	st.pop();

	if(rm_idx == cn) continue;
	for(int i = 0; i < children[cn].size(); i++) {
	  if(children[cn].size() == 1 && rm_idx == children[cn][i]) cnt++;
	  if(dirty[children[cn][i]]) continue;
	  st.push(children[cn][i]);
	  dirty[children[cn][i]] = true;
	}
	if(children[cn].size() == 0) cnt++;
  }
  cout << cnt << "\n";
  
  cout << "\n";
  return 0;
}


