#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> gra[50];
int dists[50][50];

void dijk(int st) {
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int > > > pq;
  pq.push(make_pair(0, st));
  while(!pq.empty()) {
	int dist = pq.top().first;
	int cur = pq.top().second;
	pq.pop();

	if(dists[st][cur] != -1 && dists[st][cur] <= dist) continue;
	dists[st][cur] = dist;
	for(int i = 0; i < gra[cur].size(); i++) {
	  pq.push(make_pair(dist + 1, gra[cur][i]));
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  while(true) {
	int input[2];
	cin >> input[0] >> input[1];
	if(input[0] == -1 && input[1] == -1) break;
	gra[input[0] - 1].push_back(input[1] - 1);
	gra[input[1] - 1].push_back(input[0] - 1);
  }

  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) dists[i][j] = -1;
  }
  for(int i = 0; i < n; i++) dijk(i);

  vector<int> winner;
  int winner_score = 9999999;
  for(int i = 0; i < n; i++) {
	int sc = 0;
	for(int j = 0; j < n; j++) {
	  sc = max(sc, dists[i][j]);
	}
	if(winner_score > sc) {
	  winner_score = sc;
	  winner.clear();
	  winner.push_back(i);
	} else if(winner_score == sc) {
	  winner_score = sc;
	  winner.push_back(i);
	}
  }

  cout << winner_score << " " << winner.size() << "\n";
  for(int i = 0; i < winner.size(); i++) cout << winner[i] + 1 << " ";
  cout << "\n";
  return 0;
}
