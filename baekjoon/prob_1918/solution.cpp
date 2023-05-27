#include <bits/stdc++.h>
using namespace std;

string input;
stack<char> s;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> input;
  for(int i = 0; i < input.length(); i++) {
	if(input[i] == '(') {
	  s.push(input[i]);
	} else if(input[i] == ')') {
	  while(!s.empty()) {
		char tmp = s.top();
		s.pop();
		if(tmp == '(') break;
		cout << tmp;
	  }
	} else if(input[i] == '*' || input[i] == '/') {
	  while(!s.empty() && s.top() != '(' && s.top() != '+' && s.top() != '-') {
		char tmp = s.top();
		s.pop();
		cout << tmp;
	  }
	  s.push(input[i]);
	} else if(input[i] == '+' || input[i] == '-') {
	  while(!s.empty() && s.top() != '(') {
		char tmp = s.top();
		s.pop();
		cout << tmp;
	  }
	  s.push(input[i]);
	} else {
	  cout << input[i];
	}
  }
  
  while(!s.empty()) {
	char tmp = s.top();
	s.pop();
	cout << tmp;
  }
  cout << "\n";
  return 0;
}
