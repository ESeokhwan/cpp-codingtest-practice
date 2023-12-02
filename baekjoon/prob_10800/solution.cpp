#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, pair<int, int> > balls[200000];
// (size / ( color / idx ))

int res[200000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
	balls[i].second.second = i;
	cin >> balls[i].second.first >> balls[i].first;
  }
  sort(balls, balls + n);
  
  int acc = 0;
  int acc_by_color[200001];
  vector<pair<int, int> > buffer;
  int prev_size = -1;
  memset(acc_by_color, 0, sizeof(acc_by_color));
  for(int i = 0; i < n; i++) {
	int cur_size = balls[i].first;
	int cur_color = balls[i].second.first;
	int cur_idx = balls[i].second.second;

	if(cur_size != prev_size) {
	  for(auto data : buffer) {
		acc += data.first;
		acc_by_color[data.second] += data.first;
	  }
	  buffer.clear();
	  prev_size = cur_size;
	}
	res[cur_idx] = acc - acc_by_color[cur_color];
	buffer.push_back({ cur_size, cur_color });
  }

  for(int i = 0; i < n; i++) cout << res[i] << "\n";
  return 0;
}
