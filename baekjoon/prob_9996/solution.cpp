#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  string pattern;
  string f_name;
  bool is_end;

  cin >> N >> pattern;

  string front_str;
  string back_str;
  for(int i = 0; i < pattern.length(); i++) {
	if(pattern[i] == '*') {
	  front_str = pattern.substr(0, i);
	  break;
	}
  }

  for(int i = pattern.length() - 1; i >= 0; i--) {
	if(pattern[i] == '*') {
	  back_str = pattern.substr(i+1);
	  break;
	}
  }

  for(int i = 0; i < N; i++) {
	int last_of_front = 0;
	is_end = false;
	cin >> f_name;

	for(int j = 0; j < front_str.length(); j++) {
	  if(f_name[j] != front_str[j]) {
		is_end = true;
		break;
	  }
	  last_of_front = j;
	}
	  
	int last_idx_back_str = back_str.length() - 1;
	int last_idx_f_name = f_name.length() - 1;	
	for(int j = 0; j < back_str.length(); j++) {
	  if(f_name[last_idx_f_name - j] != back_str[last_idx_back_str-j]) {
		is_end = true;
		break;
	  }
	  
	  if(last_of_front == last_idx_f_name - j) {
		is_end = true;
		break;
	  }
	}
	
	if(is_end) {
	  cout << "NE" << "\n";
	} else {
	  cout << "DA" << "\n";
	}
  }

  cout << "\n";
  return 0;
}
