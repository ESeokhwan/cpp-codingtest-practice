#include <bits/stdc++.h>
using namespace std;

int N;
string input;

stack<int> s;
int g_max;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  cin >> input;

  g_max = 0;

  int sp = 0;
  for(int i = 0; i < N; i++) {
	if(input[i] == '(') {
	  s.push(i);
	} else {
	  if(!s.empty()) {
		s.pop();
		if(s.empty()) g_max = max(g_max, i - sp + 1);
		else g_max = max(g_max, i - s.top());
	  } else {
		sp = i + 1;
	  }
	}
  }

  cout << g_max << "\n";
  cout << "\n";
  return 0;
}
