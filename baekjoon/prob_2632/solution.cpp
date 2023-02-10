#include <bits/stdc++.h>
using namespace std;

int N;
int m, n;

int a[1000];
int b[1000];

int a_sums[2000001];
int b_sums[2000001];

long long res;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  res = 0;
  cin >> N >> m >> n;


  for(int i = 0; i < m; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];

  memset(a_sums, 0, (N+1)*sizeof(int));
  memset(b_sums, 0, (N+1)*sizeof(int));
  a_sums[0] = 1;
  b_sums[0] = 1;
  int l_sum = 0;
  for(int i = 0; i < m; i++) {
	l_sum = 0;
	int s = m;
	if(i != 0) s--;
	for(int j = 0; j < s; j++) {
	  l_sum += a[(i + j) % m];
	  if(l_sum > N) break;
	  a_sums[l_sum]++;
	}
  }

  for(int i = 0; i < n; i++) {
	l_sum = 0;
	int s = n;
	if(i != 0) s--;
	for(int j = 0; j < s; j++) {
	  l_sum += b[(i + j) % n];
	  if(l_sum > N) break;
	  b_sums[l_sum]++;
	}
  }

  for(int i = 0; i < N+1; i++) {
	res += (((long long) a_sums[i]) * ((long long) b_sums[N-i]));
  }

  cout << res << "\n";
  cout << "\n";
  return 0;
}


