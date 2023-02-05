#include <bits/stdc++.h>
using namespace std;

int N;
pair< unsigned long long, unsigned long long > l[500000];

unsigned long long cnt;
stack< pair< unsigned long long, unsigned long long > > s;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cnt = 0;
  cin >> N;

  for(int i = 0; i < N; i++) {
	int input;
	cin >> input;
	
	unsigned long long asc = 1;
	if(i != 0 && l[i-1].first == input) asc += l[i-1].second;
	l[i] = make_pair(input, asc);
  }


  for(int i = 1; i < N; i++) {
	if(l[i-1].first == l[i].first) {
	  cnt += l[i].second - 1;
	  while(!s.empty()) {
		unsigned long long asc = s.top().second;
		if(s.top().first == l[i].first) {
		  cnt += asc;
		  if(s.size() > asc) cnt += 1;
		  break;
		} else if(s.top().first > l[i].first) {
		  cnt += 1;
		  break;
		} else {
		  cnt += asc;
		  for(unsigned long long j = 0; j < asc; j++) s.pop();
		  continue;
		}
	  }
	  
	} else if(l[i-1].first > l[i].first) {
	  cnt += 1;
	  unsigned long long asc = l[i-1].second;
	  unsigned long long sp = 1;
	  if(!s.empty()) {
		if(s.top().first == l[i-1].first) sp += s.top().second;
	  }
	  for(unsigned long long j = sp; j <= asc; j++) s.push(make_pair(l[i-1].first, j));
	} else {
	  cnt += l[i-1].second;
	  while(!s.empty()) {
		unsigned long long asc = s.top().second;
		if(s.top().first == l[i].first) {
		  cnt += asc;
		  if(s.size() > asc) cnt += 1;
		  break;
		} else if(s.top().first > l[i].first) {
		  cnt += 1;
		  break;
		} else {
		  cnt += asc;
		  for(unsigned long long j = 0; j < asc; j++) s.pop();
		  continue;
		}
	  }
	}
  }

  cout << cnt << "\n";
  cout << "\n";
  return 0;
}


