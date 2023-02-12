#include <bits/stdc++.h>
using namespace std;

int N, K;

pair<int, int> gems[300000];
int bags[300000];

priority_queue<int, vector<int>, greater<int> > pq;

bool cmp_gems(pair<int, int> a, pair<int, int> b) {
  return a.first > b.first;
}

bool cmp_bags(int a, int b) {
  return a > b;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;

  for(int i = 0; i < N; i++) cin >> gems[i].first >> gems[i].second;

  for(int i = 0; i < K; i++) cin >> bags[i];

  sort(gems, gems+N, cmp_gems);
  sort(bags, bags+K, cmp_bags);

  int bag_idx = 0;
  for(int i = 0; i < N; i++) {
	int gem_m = gems[i].first;
	int gem_v = gems[i].second;

	if(bags[bag_idx] >= gem_m) {
	  pq.push(gem_v);
	  bag_idx++;
	} else {
	  if(!pq.empty() && pq.top() < gem_v) {
		pq.pop();
		pq.push(gem_v);
	  }
	}
  }

  long long res = 0;
  while(!pq.empty()) {
	res += pq.top();
	pq.pop();
  }

  cout << res << "\n";
  cout << "\n";
  return 0;
}
