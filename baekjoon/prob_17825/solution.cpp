#include <bits/stdc++.h>
using namespace std;

int res;
int dices[10];
int p[4];

pair<int, int> ne[32] = {
  { 1, 1 }, {2, 2}, {3, 3}, {4, 4}, {5, 5}, // 4
  {6, 21}, {7, 7}, {8, 8}, {9, 9}, {10, 10}, // 9
  {11, 24}, {12, 12}, {13, 13}, {14, 14}, {15, 15}, // 14
  {16, 26}, {17, 17}, {18, 18}, {19, 19}, {20, 20}, { 32, 32 }, // 20
  {22, 22}, {23, 23}, {29, 29},  // 23
  {25, 25}, {29, 29}, // 25
  {27, 27}, {28, 28}, {29, 29}, // 28
  {30, 30}, {31, 31}, {20, 20} // 31
};

int val[33] = { 
  0, 2, 4, 6, 8, // 4
  10, 12, 14, 16, 18, // 9
  20, 22, 24, 26, 28, // 14
  30, 32, 34, 36, 38, 40, // 20
  13, 16, 19, // 23
  22, 24, // 25
  28, 27, 26, // 28
  25, 30, 35, // 31
  0 // 32
};

void rec(int acc, int cnt) {
  if (cnt == 10) {
	res = max(res, acc);
	return;
  }
  
  bool all_pass = true;
  for (int i = 0; i < 4; i++) {
	if (p[i] == 32) continue;
	
	int prev = p[i];
	p[i] = ne[p[i]].second;
	for (int j = 1; j < dices[cnt]; j++) {
	  if(p[i] >= 32) continue;
	  p[i] = ne[p[i]].first;
	}
	bool on_same_spot = false;
	for (int j = 0; j < 4; j++) {
	  if (i == j) continue;
	  if (p[i] != 32 && p[i] == p[j]) {
		on_same_spot = true;
	  }
	}
	if (!on_same_spot) {
	  rec(acc + val[p[i]], cnt + 1);
	  all_pass = false;
	}
	p[i] = prev;
  }
  if (all_pass) {
	rec(acc, cnt + 1);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 4; i++) p[i] = 0;
  for (int i = 0; i < 10; i++) cin >> dices[i];
  res = 0;
  rec(0, 0);
  cout << res << "\n";
  return 0;
}
