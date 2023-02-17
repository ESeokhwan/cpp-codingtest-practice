#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll s_atk;
int r_info[123456][3];
ll atk_info[123456];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> s_atk;
  
  for(int i = 0; i < N; i++) {
	cin >> r_info[i][0] >> r_info[i][1] >> r_info[i][2];
  }

  for(int i = 0; i < N; i++) {
	atk_info[i] = s_atk;
	if(r_info[i][0] == 2) {
	  s_atk += r_info[i][1];
	}
  }

  ll st = 1L;
  ll en = 123456L * 1000000L * 1000000L;
  while(st < en) {
	ll ex = (st + en) / 2;
	bool fail = false;
	ll c_hp = ex;
	for(int i = 0; i < N; i++) {
	  if(r_info[i][0] == 1) {
		ll e_atk = r_info[i][1];
		ll e_hp = r_info[i][2];

		ll atk_cnt = e_hp / atk_info[i];
		if(e_hp % atk_info[i] != 0) atk_cnt += 1;

		c_hp -= ((atk_cnt - 1) * e_atk);
		if(c_hp <= 0) {
		  fail = true;
		  break;
		}
	  } else if(r_info[i][0] == 2) {
		c_hp += r_info[i][2];
		if(c_hp > ex) c_hp = ex;
	  }
	}

	if(fail) st = ex + 1;
	else en = ex;
  }

  cout << st << "\n";
  cout << "\n";
  return 0;
}



