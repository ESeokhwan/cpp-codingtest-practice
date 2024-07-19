#include "bits/stdc++.h"
using namespace std;

int n;
int m;
int min_price, min_price_num;
int prices[10];
int output[55];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  min_price = 55;
  cin >> n;
  for (int i = 0; i < n; i++) {
	cin >> prices[i];
	if (min_price >= prices[i]) {
	  min_price = prices[i];
	  min_price_num = i;
	}
  }
  cin >> m;

  if (n == 1) {
	cout << "0\n";
	return 0;
  }

  int remain_budget = m;
  memset(output, -1, sizeof(output));
  
  int idx = 0;
  while (true) {
	int new_digit = min_price_num;
	int cur_p = min_price;
	if (idx == 0 && new_digit == 0) {
	  int second_min_price = 55;
	  int second_min_price_num;
	  for (int i = 1; i < n; i++) {
		if (second_min_price > prices[i]) {
		  second_min_price = prices[i];
		  second_min_price_num = i;
		}
	  }
	  new_digit = second_min_price_num;
	  cur_p = prices[second_min_price_num];
	}
	if (remain_budget < cur_p) break;
	remain_budget -= cur_p;
	output[idx] = new_digit;
	idx += 1;
  }
  
  for (int i = 0; output[i] != -1; i++) {
	for (int j = n - 1; j >= 0; j--) {
	  if (j <= output[i]) break;
	  if (remain_budget >= prices[j] - prices[output[i]]) {
		remain_budget -= (prices[j] - prices[output[i]]);
		output[i] = j;
		break;
	  }
	}
  }

  idx = 0;
  while(output[idx] != -1) {
	cout << output[idx];
	idx+= 1;
  }
  if (idx == 0) cout << "0";
  cout << "\n";
}


