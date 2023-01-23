#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  long long res = 1;
  for(long long i = 2; i <= b; i++) {
	if(i > a) break;
	if(a % i == 0 && b % i == 0) res = i;
  }
  return res;
}

long long solution(long long a, long long b) {
  while(a != 1) {
	long long x = (b / a) + 1;
	a = x * a - b;
	b = x * b;
	long long div = gcd(a, b);
	a = a / div;
	b = b / div;
  }
  return b;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  for(int i = 0; i < N; i++) {
	long long a, b;
	cin >> a >> b;
	long long sol = solution(a, b);
	cout << sol << "\n";
  }

  cout << "\n";
  return 0;
}


