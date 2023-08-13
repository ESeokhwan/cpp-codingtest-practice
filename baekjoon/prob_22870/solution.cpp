#include <bits/stdc++.h>
using namespace std;

int n, m, s, e;
int res;
vector<pair<int, int> > edges[200000];

int dist[200000];
int pre[200000];

class cmp {
  public :
  bool operator() (
	  const pair<int, pair<int, int> > &lhs, 
	  const pair<int, pair<int, int> > &rhs
  ) {
	if(lhs.first == rhs.first) {
	  if(lhs.second.first == rhs.second.first) {
		return lhs.second.second > rhs.second.second;
	  }
	  return lhs.second.first > rhs.second.first;
	}
	return lhs.first > rhs.first;
  }
};

bool cmp_prevs(int en1, int en2) {
  vector<int> prevs1;
  vector<int> prevs2;
  int tmp = en1;
  while(tmp != -1) {
	prevs1.push_back(tmp);
	tmp = pre[tmp];
  }
  
  tmp = en2;
  while(tmp != -1) {
	prevs2.push_back(tmp);
	tmp = pre[tmp];
  }
  for(int i = 0; i < min(prevs1.size(), prevs2.size()); i++) {
	int idx1 = prevs1.size() - i - 1;
	int idx2 = prevs2.size() - i - 1;
	if(prevs1[idx1] == prevs2[idx2]) continue;
	if(prevs1[idx1] < prevs2[idx2]) return false;
	return true;
  }
  return true;
}

void get_route(int st, int en, set<int> exclude) {
  priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, cmp> pq;
  memset(dist, -1, sizeof(dist));
  memset(pre, -1, sizeof(pre));
  pq.push(make_pair(0, make_pair(st, -1)));
  while(!pq.empty()) {
	int cur_dist = pq.top().first;
	int cur_pos = pq.top().second.first;
	int pre_pos = pq.top().second.second;
	pq.pop();

	if(dist[cur_pos] == -1 || dist[cur_pos] > cur_dist
		|| (dist[cur_pos] == cur_dist && cmp_prevs(pre[cur_pos], pre_pos))) {
	  pre[cur_pos] = pre_pos;
	  dist[cur_pos] = cur_dist;
	  for(pair<int, int> edge: edges[cur_pos]) {
		if(exclude.count(edge.first) == 0) {
		  pq.push(make_pair(cur_dist + edge.second, make_pair(edge.first, cur_pos)));
  	    }
	  }
	}
  }
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
	int input[3];
	cin >> input[0] >> input[1] >> input[2];
	edges[input[0] - 1].push_back(make_pair(input[1] - 1, input[2]));
	edges[input[1] - 1].push_back(make_pair(input[0] - 1, input[2]));
  }
  cin >> s >> e;

  set<int> routes;
  get_route(s - 1, e - 1, routes); 

  res = dist[e - 1];
  int cur_pos = e - 1;
  while(cur_pos != -1) {
	if(cur_pos != e - 1 && cur_pos != s - 1) {
	  routes.insert(cur_pos);
	}
	cur_pos = pre[cur_pos];
  }

  get_route(e - 1, s - 1, routes);
  res += dist[s - 1];
  cout << res << "\n";
  return 0;
}
