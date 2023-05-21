#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
pair<ll, ll> points[10000];

long double calc_tri(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
  return ((long double) (x1*y2) + (x2*y3) + (x3*y1) - (x1*y3) - (x3*y2) - (x2*y1)) * 0.5L;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> points[i].first >> points[i].second;

  long double res = 0.0L;
  for(int i = 1; i < n-1; i++) {
	long double tmp = calc_tri(points[0].first, points[0].second, points[i].first, points[i].second, points[i+1].first, points[i+1].second);
	res += tmp;
  }
  res = abs(res);
  res = round(res * 10.0L) / 10.0L;
  
  printf ("%.1Lf\n", res);
  return 0;
}
