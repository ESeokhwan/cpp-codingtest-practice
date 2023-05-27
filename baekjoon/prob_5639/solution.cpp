#include <bits/stdc++.h>
using namespace std;

int input[10001];

void rec(int st, int en) {
  if(st == en) return;

  int rt = input[st];
  int mid = en;
  for(int i = st + 1; i < en; i++) {
	if(input[i] > rt) {
	  mid = i;
	  break;
	}
  }
  rec(st + 1, mid);
  rec(mid, en);
  cout << rt << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cnt = 0;
  
  while (cin >> input[cnt++]);
  rec(0, cnt - 1);
  return 0;
}
