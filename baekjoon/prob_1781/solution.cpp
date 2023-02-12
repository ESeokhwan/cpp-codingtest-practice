#include <bits/stdc++.h>
using namespace std;

int N;

vector< pair<int, int> > prob_list;

bool cmp_prob(pair<int, int> a, pair<int, int> b) {
  if(a.first > b.first) return true;
  if(a.first < b.first) return false;
  return a.second > b.second;
}

priority_queue <int> pq;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for(int i = 0; i < N; i++) {
	int due, reward;
	cin >> due >> reward;
	prob_list.push_back(make_pair(due, reward));
  }
  sort(prob_list.begin(), prob_list.end(), cmp_prob);
 
  int res = 0;
  int start_idx = 0;
  int i = prob_list[start_idx].first;
  while(i > 0) {
	for(int j = start_idx; j < prob_list.size(); j++) {
	  if(prob_list[j].first < i) break;
	  pq.push(prob_list[j].second);
	  start_idx = j+1;
	}
	if(!pq.empty()) {
	  res += pq.top();
	  pq.pop();
	}

	if(pq.empty() && start_idx == N) break;
	if(pq.empty() && start_idx != N) {
	  i = prob_list[start_idx].first;
	  continue;
	}
	i = i-1;
  }

  cout << res << "\n";
  cout << "\n";
  return 0;
}

