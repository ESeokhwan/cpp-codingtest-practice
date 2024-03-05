#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int p_len;
char p[100000];
int x[100000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  for(int i = 0; i < t; i++) {
	string input;
	cin >> input;
	p_len = 0;
	for(int j = 0; j < input.size(); j++) {
	  p[j] = input[j];
	  p_len += 1;
	}
	
	cin >> n;
	cin >> input;
	string tmp = "";
	int x_idx = 0;
	for(int j = 1; j < input.size(); j++) {
	  if (input[j] == ']' && j == 1) break;
	  if (input[j] == ',' || input[j] == ']') {
		x[x_idx] = stoi(tmp);
		x_idx += 1;
		tmp = "";
	  } else {
		tmp += input[j];
	  }
	}

	int st = 0;
	int en = n - 1;
	bool flip = false;
	for (int j = 0; j < p_len; j++) {
	  if(p[j] == 'R') {
		flip = !flip;
		continue;
	  }
	  
	  if(flip) {
		en -= 1;
	  } else {
		st += 1;
	  }
	}
	if (en == st - 1) {
	  cout << "[]\n";
	} else if(en < st) {
	  cout << "error\n";
	} else {
	  cout << "[";
	  if (flip) {
		for(int j = en; j > st; j--) {
		  cout << x[j] << ",";
		}
		cout << x[st] << "]\n";
	  } else {
	    for(int j = st; j < en; j++) {
		  cout << x[j] << ",";
	    }
	    cout << x[en] << "]\n";
	  }
	}
  }
  return 0;
}
