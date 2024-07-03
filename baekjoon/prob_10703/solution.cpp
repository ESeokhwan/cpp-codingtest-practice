#include <bits/stdc++.h>
using namespace std;

int r, c;
char _map[3000][3000];
char new_map[3000][3000];

int lowest_meteo[3000];
int highest_ground[3000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
	for (int j = 0; j < c; j++) {
	  cin >> _map[i][j];
	}
  }

  memset(lowest_meteo, -1, sizeof(lowest_meteo));
  memset(highest_ground, -1, sizeof(highest_ground));

  for (int j = 0; j < c; j++) {
	for (int i = 0; i < r; i++) {
	  if (_map[i][j] == 'X') {
		lowest_meteo[j] = i;
	  } else if (_map[i][j] == '#' && highest_ground[j] == -1) {
		highest_ground[j] = i;
	  }
	}
  }

  int min_dist = 987654321;
  for (int i = 0; i < c; i++) {
	if (lowest_meteo[i] == -1) {
	  continue;
	}
	min_dist = min(min_dist, highest_ground[i] - lowest_meteo[i]);
  }

  for (int i = 0; i < r; i++) {
	for (int j = 0; j < c; j++) {
	  if (_map[i][j] == '#') {
		new_map[i][j] = '#';
	  } else {
		new_map[i][j] = '.';
	  }
	}
  }
  
  for (int i = 0; i < r; i++) {
	for (int j = 0; j < c; j++) {
	  if (_map[i][j] == 'X') {
		new_map[i + min_dist - 1][j] = 'X';
	  }
	}
  }

  for (int i = 0; i < r; i++) {
	for (int j = 0; j < c; j++) {
	  cout << new_map[i][j];
	}
	cout << "\n";
  }
  return 0;
}
