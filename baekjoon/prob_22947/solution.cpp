#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int n, m, k;

ll task_times[105];

vector<int> next_tasks[105];
int indegs[105];

int need_removed_task = -1;

int last_task;
ll res = LLONG_MAX / 2;

ll topol_sort() {
  int tmp_last_task;
  int tmp_indegs[105];
  for (int i = 0; i < n; i++) {
	tmp_indegs[i] = indegs[i];
  }

  ll cur_time = 0;
  ll max_duration = 0;
  priority_queue<pair<ll, int >, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
  pq.push({ cur_time + task_times[0], 0 });
  while (!pq.empty()) {
	ll closest_time = pq.top().first;
	int cur_task = pq.top().second;
	ll duration = closest_time - cur_time;
	tmp_last_task = cur_task;
//	cout << closest_time << " cur_time " << cur_time << "\n";
	pq.pop();

	bool trigger_next = false;
	cur_time = closest_time;
	for (int next_task: next_tasks[cur_task]) {
	  tmp_indegs[next_task] -= 1;
	  if (tmp_indegs[next_task] == 0) {
		pq.push({ cur_time + task_times[next_task], next_task });
		trigger_next = true;
	  }
	}
	
//	if (max_duration < duration && trigger_next) {
//	  max_duration = duration;
//	  need_removed_task = cur_task;
//	}
  }

  last_task = tmp_last_task;
  return cur_time;
}

void combi(vector<int> &tars)  {
  if (tars.size() == k) {
//	for (int tar: tars) {
//	  cout << tar + 1 << " ";
//	}
//	cout << "\n";
	ll sub_res = topol_sort();
	res = min(sub_res, res);
	return;
  }

  int last_ele = 0;
  if (tars.size() != 0) {
	last_ele = tars.back();
  }

  for (int i = last_ele + 1; i < n - (k - tars.size() - 1); i++) {
	if (i == last_task) continue;
	ll tmp_time = task_times[i];
	tars.push_back(i);
	task_times[i] = 0;
	combi(tars);
	tars.erase(tars.end() - 1);
	task_times[i] = tmp_time;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
	cin >> task_times[i];
  }

  memset(indegs, 0, sizeof(indegs));
  for (int i = 0; i < m; i++) {
	int input1, input2;
	cin >> input1 >> input2;
	next_tasks[input1 - 1].push_back(input2 - 1);
	indegs[input2 - 1] += 1;
  }

//  for (int i = 0; i < k; i++) {
//	topol_sort();
//	task_times[need_removed_task] = 0;
//  }
//  cout << topol_sort().second << "\n";

  topol_sort();
  vector<int> container;
  combi(container);
  cout << res << "\n";
  return 0;
}
