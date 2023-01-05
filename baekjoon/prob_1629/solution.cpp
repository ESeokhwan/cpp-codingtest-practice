#include <bits/stdc++.h>
using namespace std;

long long recursion(long long acc, long long a, long long b, long long c) {
  long long tmp = a;
  long long output, last_loop;
  for(long long i = 1; i <= b; i *= 2) {
	if(i != 1) tmp = output * output;
	output = tmp % c;
	last_loop = i;
  }

  if(b == 0) {
	return acc % c;
  } else {
	return (acc * recursion(output, a, b - last_loop, c)) % c;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long a, b, c;
  long long tmp, output;

  long long last_loop;

  cin >> a >> b >> c;

  output = recursion(1, a, b, c);
  
  cout << output << "\n";
  return 0;
}
