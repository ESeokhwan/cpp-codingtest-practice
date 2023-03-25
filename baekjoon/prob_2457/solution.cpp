#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> flowers[100000];

int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int getDays(int month, int day) {
  int output = day;
  for(int i = 0; i < month; i++) {
	output += months[i];
  }
  return output;
}

class compare_second {
public:
  compare_second() {
  }

  bool operator() (const pair<int, int>& lhs, const pair<int, int> &rhs) const
  {
    return (lhs.second < rhs.second);
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int st = getDays(3, 1);
  int en = getDays(11, 30);

  cin >> n;
  for(int i = 0; i < n; i++) {
	int input[4];
	cin >> input[0] >> input[1] >> input[2] >> input[3];
	flowers[i] = make_pair(getDays(input[0], input[1]), getDays(input[2], input[3]));
  }

  sort(flowers, flowers+n);
  priority_queue<pair<int, int>, vector<pair<int, int> >, compare_second > pq;

  int idx = 0;
  int cnt = 0;
  bool is_end = false;
  while(idx < n) {
	for(int i = idx; i <= n; i++) {
	  if(i == n) idx = n;
	  if(flowers[i].first > st) {
		idx = i;
		break;
	  }
	  pq.push(flowers[i]);
	}
	if(pq.empty()) break;
  
	st = max(st, pq.top().second);
	cnt++;
	if(pq.top().second > en) {
	  is_end = true;
	  break;
	}
	pq.pop();
  }

  if(is_end) cout << cnt << "\n";
  else cout << "0\n";
  return 0;
}
