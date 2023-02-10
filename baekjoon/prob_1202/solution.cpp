#include <bits/stdc++.h>
using namespace std;

int N, K;

vector< pair<int, int> > gems;
vector< int > bags;

priority_queue<int> pq;

bool cmp_gems(pair<int, int> a, pair<int, int> b) {
  if(a.first < b.first) return true;
  if(a.first > b.first) return false;
  return a.second > b.second;
}

bool cmp_bags(int a, int b) {
  return a < b;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;

  for(int i = 0; i < N; i++) {
	int m, v;
	cin >> m >> v;
	gems.push_back(make_pair(m, v));
  }

  for(int i = 0; i < K; i++) {
	int m;
	cin >> m;
	bags.push_back(m);
  }

  sort(gems.begin(), gems.end(), cmp_gems);
  sort(bags.begin(), bags.end(), cmp_bags);

  long long res = 0;
  int start_idx = 0;
  for(int i = 0; i < K; i++) {
	for(int j = start_idx; j < N; j++) {
	  if(gems[j].first > bags[i]) break;
	  pq.push(gems[j].second);
	  start_idx = j+1;
	}
	
	if(pq.empty()) {
	  if(start_idx == N) break;
	} else {
	  res += pq.top();
	  pq.pop();
	}
  }

  cout << res << "\n";
  cout << "\n";
  return 0;
}
