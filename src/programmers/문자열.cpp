#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer{100};

void dfs(string begin, string target, vector<string> words, vector<bool>& visit, int cnt = 0){
    for (int i = 0; i < words.size(); i++) {
        int count{ 0 };
        for (int j = 0; j < words[i].length(); j++)
            if (!visit[i] && begin[j] != words[i][j])    count++;
        if (count == 1) {
            if (target == words[i] && answer > cnt + 1) {
                answer = cnt + 1;
                return;
            }
            visit[i] = true;
            dfs(words[i], target, words, visit, cnt + 1);
            visit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<string>::iterator iter = find(words.begin(), words.end(), target);
    if(iter == words.end()){
        return 0;
    }
    vector<bool> visit(words.size(), false);
    dfs(begin, target, words, visit);
    return answer;
}

@https://mungto.tistory.com/53 참고
