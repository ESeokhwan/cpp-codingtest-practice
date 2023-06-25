#include <bits/stdc++.h>
using namespace std;

char a[300000];
char b[300000];
char res[300000];

bool dsc(char i, char j) { return (i>j); }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string str;
  cin >> str;
  for(int i = 0; i < str.size(); i++) a[i] = str[i];
  
  cin >> str;
  for(int i = 0; i < str.size(); i++) b[i] = str[i];
  sort(a, a + str.size());
  sort(b, b + str.size(), dsc);

  int st = 0;
  int en = str.size() - 1;
  
  int st_a = 0;
  int en_a = (str.size() + 1) / 2 - 1;
  int st_b = 0;
  int en_b = str.size() / 2 - 1;
  for(int i = 0; i < str.size(); i++) {
	if(i % 2 == 0) {
	  if(st_b > en_b || a[st_a] < b[st_b]) {
		res[st] = a[st_a];
		st_a += 1;
		st += 1;
	  } else {
		res[en] = a[en_a];
		en_a -= 1;
		en -= 1;
	  }
	} else {
	  if(st_a > en_a || b[st_b] > a[st_a]) {
		res[st] = b[st_b];
		st_b += 1;
		st += 1;
	  } else {
		res[en] = b[en_b];
		en_b -= 1;
		en -= 1;
	  }
	}
  }

  for(int i = 0; i < str.size(); i++) cout << res[i];
  cout << "\n";
  return 0;
}
