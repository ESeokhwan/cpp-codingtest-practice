#include <bits/stdc++.h>
using namespace std;

int N;
int l[500000];

int cnt;
stack< int > s;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cnt = 0;
  cin >> N;

  for(int i = 0; i < N; i++) {
	int input;
	cin >> input;
	l[i] = input;
  }

  int dec = 0;
  s.push(l[0]);
  for(int i = 0; i < N-1; i++) {
	if(l[i] <= l[i+1]) {
	  cnt++;
	  if(dec != 0) {
		cnt += (dec-1);
		dec = 0;
	  }
	  while(!s.empty()) {
		cnt++;
		if(s.top() < l[i]) {
		  s.pop();
		  continue;
		}
		break;
	  }
	} else {
	  if(i != 0 && l[i-1] <= l[i]) {
		while(!s.empty()) {
		  cnt++;
		  if(s.top() < l[i]) {
			s.pop();
			continue;
		  }
		  break;
		}
	  }
	  s.push(l[i]);
	  dec++;
	}
  }

  if(N != 1) {
	if(l[N-2] <= l[N-1]) {
	  while(!s.empty()) {
		cnt++;
		if(s.top() < l[N-1]) {
		  s.pop();
		  continue;
		}
		break;
	  }
	}
  }

  cout << cnt << "\n";
  cout << "\n";
  return 0;
}
