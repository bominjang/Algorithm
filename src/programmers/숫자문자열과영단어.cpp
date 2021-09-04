#include <algorithm>
#include <string>
#include <map>

using namespace std;
map<string, string> m;

void insertData() {
    m.insert(pair<string , string>("0", "zero"));
    m.insert(pair<string, string>("1", "one"));
    m.insert(pair<string, string>("2", "two"));
    m.insert(pair<string, string>("3", "three"));
    m.insert(pair<string, string>("4", "four"));
    m.insert(pair<string, string>("5", "five"));
    m.insert(pair<string, string>("6", "six"));
    m.insert(pair<string, string>("7", "seven"));
    m.insert(pair<string, string>("8", "eight"));
    m.insert(pair<string, string>("9", "nine"));
}

//영단어 -> 숫자
int solution(string s) {
    insertData();

    string answer = "";

    while (!s.empty()) {
        map<string, string>::iterator iter;
        //숫자이면
        if (s[0] >= '0' && s[0] <= '9') {
            answer += s[0];
            s.erase(0,1);
            continue;
        }
        for (iter = m.begin(); iter != m.end(); iter++) {
            int spos = s.find(iter->second, 0);
            //string일 경우 int로 변환
            if (spos != string::npos && spos == 0) {
                answer += iter->first;
                s.erase(0, iter->second.size());
            }
        }
    }

    return stoi(answer);
}
