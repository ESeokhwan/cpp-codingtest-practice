#include <bits/stdc++.h>
using namespace std;

int n;
int line[1000000];

bool is_visited[1000001];
int prev_seq[1000002];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> line[i];

  for(int i = 0; i < n; i++) {
	int tar = line[i];
	is_visited[tar] = true;
	if(!is_visited[tar+1]) prev_seq[tar+1] = prev_seq[tar] + 1;
  }

  int max_con = 0;
  for(int i = 1; i <= n; i++) max_con = max(max_con, prev_seq[i]);

  cout << n - max_con - 1  << "\n";
  cout << "\n";
  return 0;
}
