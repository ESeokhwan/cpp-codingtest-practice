#include <bits/stdc++.h>
using namespace std;

string input;
string key;

stack<pair<char, int> > s;

void print() {
  if(s.empty()) return;
  char tmp = s.top().first;
  s.pop();
  print();
  cout << tmp;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t_cnt = 0;
  cin >> input >> key;
  for(int i = 0; i < input.length(); i++) {
	if(input[i] == key[t_cnt]) t_cnt += 1;
	else if(input[i] == key[0]) t_cnt = 1;
	else t_cnt = 0;
	s.push(make_pair(input[i], t_cnt));
	
	if(t_cnt == key.length()) {
	  for(int i = 0; i < key.length(); i++) s.pop();
	  if(s.empty()) t_cnt = 0;
	  else t_cnt = s.top().second;
	}
  }

  if(s.empty()) {
	cout << "FRULA\n";
  } else {
	print();
	cout << "\n";
  }
  return 0;
}
