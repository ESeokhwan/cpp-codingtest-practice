#include <bits/stdc++.h>
using namespace std;

int n, s;

int n1, n2;
int nums1[20];
int nums2[20];

long long sum1[4000001];
long long sum2[4000001];

int to_val(int idx) {
  return idx - 2000000;
}

int to_idx(int x) {
  return x + 2000000;
}

void make_sums1(int idx, int acc) {
  if(idx == n1) {
	sum1[to_idx(acc)]++;
	return;
  }
  make_sums1(idx+1, acc + nums1[idx]);
  make_sums1(idx+1, acc);
}

void make_sums2(int idx, int acc) {
  if(idx == n2) {
	sum2[to_idx(acc)]++;
	return;
  }
  make_sums2(idx+1, acc + nums2[idx]);
  make_sums2(idx+1, acc);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(sum1, 0L, sizeof(sum1));
  memset(sum2, 0L, sizeof(sum2));

  cin >> n >> s;
  n1 = n / 2;
  n2 = n - n1;

  for(int i = 0; i < n1; i++) cin >> nums1[i];
  for(int i = 0; i < n2; i++) cin >> nums2[i];

  make_sums1(0, 0);
  make_sums2(0, 0);

  long long res = 0;
  for(int i = 0; i < 4000001; i++) {
	if(to_idx(s - to_val(i)) >= 4000001 || to_idx(s - to_val(i)) < 0) continue;
	res += sum1[i] * sum2[to_idx(s - to_val(i))];
  }
  if(s == 0) res -= 1;

  cout << res << "\n";
  return 0;
}

