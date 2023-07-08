#include <bits/stdc++.h>
using namespace std;

string input;
int sc[100000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> input;

  if(input[0] == '(') sc[0] = 1;
  else sc[0] = -1;
  for(int i = 1; i < input.size(); i++) {
	if(input[i] == '(') sc[i] = sc[i - 1] + 1;
	if(input[i] == ')') sc[i] = sc[i - 1] - 1;
  }

  int res = 0;
  if(sc[input.size() - 1] == -2) {
	for(int i = 0; i < input.size(); i++) {
	  if(input[i] == ')') res += 1;
	  if(sc[i] < 0) break;
	}
  } else if(sc[input.size() - 1] == 2) {
	for(int i = input.size() - 1; i >= 0; i--) {
	  if(sc[i] == 1) break;
	  if(input[i] == '(') res += 1;
	}
  }

  cout << res << "\n";
  return 0;
}
