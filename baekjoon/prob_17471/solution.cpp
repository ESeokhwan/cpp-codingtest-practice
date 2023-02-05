#include <bits/stdc++.h>
using namespace std;

int N, M;

int po[10];
vector<int> re[10];
bool is_a[10];

int total_po;
int res;

void get_po_diff() {
  int l_res;

  int po_a = 0;
  int po_b = total_po;

  int a_cnt = 0;
  int b_cnt = N;
  for(int i = 0; i < N; i++) {
	if(is_a[i]) {
	  po_a += po[i];
	  po_b -= po[i];
	  a_cnt++;
	  b_cnt--;
	}
  }
  l_res = abs(po_a - po_b);

  if(res != -1 && l_res > res) return;

  queue<int> q;
  bool visited[10];
  memset(visited, false, 10*sizeof(bool));
  
  int sp = 0;
  q.push(sp);
  visited[sp] = true;
  while(!q.empty()) {
	int cp = q.front();
	q.pop();
	a_cnt--;
	for(int np : re[cp]) {
	  if(visited[np] || !is_a[np]) continue;
	  q.push(np);
	  visited[np] = true;
	}
  }
  if(a_cnt != 0) return;

  
  memset(visited, false, 10*sizeof(bool));
  sp = -1;
  for(int i = 0; i < N; i++) {
	if(!is_a[i]) {
	  sp = i;
	  break;
	}
  }
  if(sp == -1) return;

  q.push(sp);
  visited[sp] = true;
  while(!q.empty()) {
	int cp = q.front();
	q.pop();
	b_cnt--;
	for(int np : re[cp]) {
	  if(visited[np] || is_a[np]) continue;
	  q.push(np);
	  visited[np] = true;
	}
  }
  if(b_cnt != 0) return;

  res = l_res;
}

int cnt1 = 0;
void rec(int cn) {
  if(cn == N) return;
  get_po_diff();
  is_a[cn+1] = true;
  rec(cn+1);
  is_a[cn+1] = false;
  rec(cn+1);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  res = -1;
  total_po = 0;
  for(int i = 0; i < N; i++) {
	cin >> po[i];
	total_po += po[i];
  }

  for(int i = 0; i < N; i++) {
	cin >> M;
	for(int j = 0; j < M; j++) {
	  int input;
	  cin >> input;
	  re[i].push_back(input-1);
	}
  }

  memset(is_a, false, 10*sizeof(bool));
  is_a[0] = true;
  rec(0);

  cout << res << "\n";
  cout << "\n";
  return 0;
}

