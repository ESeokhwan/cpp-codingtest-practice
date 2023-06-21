#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int upper[500000];
int lower[500000];

int sorted_upper[500000];
int sorted_lower[500000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
	cin >> a >> b;
	upper[i] = a + b;
	sorted_upper[i] = a + b;
	lower[i] = a - b;
	sorted_lower[i] = a - b;
  }
  sort(sorted_upper, sorted_upper+n);
  sort(sorted_lower, sorted_lower+n);

  for(int i = 0; i < n; i++) {
	cout << lower_bound(sorted_upper, sorted_upper + n, lower[i]) - sorted_upper + 1 << " ";
	cout << upper_bound(sorted_lower, sorted_lower + n, upper[i]) - sorted_lower << "\n";
  }

  return 0;
}
