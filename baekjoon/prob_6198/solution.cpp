#include <bits/stdc++.h>

using namespace std;


int n;
int h[80000];
stack<int> s;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> h[i];

  long long cnt = 0;
  for(int i = 0; i < n; i++) {
	while(!s.empty()) {
	  if(s.top() > h[i]) break;
	  s.pop();
	  cnt += s.size();
	}
	s.push(h[i]);
  }
  while(!s.empty()) {
	s.pop();
	cnt += s.size();
  }

  cout << cnt << "\n";
  return 0;
}
