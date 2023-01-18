#include <bits/stdc++.h>

using namespace std;

int N, M;

int min_res = 987654321;
vector< int > nums;

void recursion(int cur_digit, bool isFirst, int total_digit, int acc) {
  if(cur_digit == 0) {
	int res = total_digit + abs(acc - N);
	if(res < min_res) min_res = res;
	return;
  }

  for(int i = 0; i < nums.size(); i++) {
	if(total_digit != 1 && isFirst && nums[i] == 0) continue;
	
	int mult = pow(10, cur_digit-1);
	if(i-1 >= 0) {
	  if((acc * 10 + nums[i]) * mult > N && (acc * 10 + nums[i-1]) * mult > N) break;
	}
	recursion(cur_digit - 1, false, total_digit, acc * 10 + nums[i]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 0; i < 10; i++) nums.push_back(i);

  cin >> N;
  cin >> M;
  
  for(int i = 0; i < M; i++) {
	int br_n;
	cin >> br_n;
	for(int j = 0; j < nums.size(); j++) {
	  if(nums[j] == br_n) nums.erase(nums.begin() + j);
	}
  }

  int cnt = 0;
  for(int i = N; i > 0; i/=10) {
	cnt++;
  }

  recursion(0, true, 0, 100);
  for(int i = 0; i <= cnt; i++) {
	recursion(i+1, true, i+1, 0);
  }

  cout << min_res << "\n";
  cout << "\n";
  return 0;
}




