#include <string>
#include <vector>

using namespace std;

bool check(vector<string> &want, vector<int> &number, string cur_discount) {
    for(int i = 0; i < want.size(); i++) {
        if(want[i].compare(cur_discount) == 0 && number[i] > 0) {
            number[i] -= 1;
            return true;
        }
    }
    return false;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i = 0; i < discount.size(); i++) {
        if(discount.size() - i < 10) break;
        vector<string> tmp_want = want;
        vector<int> tmp_number = number;
        
        bool failed = false;
        for(int j = 0; j < 10; j++) {
            string cur_dis = discount[i + j];
            if(!check(tmp_want, tmp_number, cur_dis)) {
                failed = true;
                break;
            }
        }
        if(!failed) answer += 1;
    }
    return answer;
}
