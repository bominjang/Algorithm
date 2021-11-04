#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> p{{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
vector<int> cor(3);

vector<int> findMax(vector<int> answer){
    int max = *max_element(cor.begin(), cor.end());
    
    for(int i=0;i<cor.size();i++){
        if(cor[i]==max){
            answer.push_back(i+1);
        }
    }
    return answer;
}

vector<int> solution(vector<int> answers) {
    int n = answers.size();
    int p0 = p[0].size(), p1=p[1].size(), p2=p[2].size();
    int a;
    for(int i=0;i<n;i++){
        a= answers[i];
        if(p[0][i%p0]==a) cor[0]++;
        if(p[1][i%p1]==a) cor[1]++;
        if(p[2][i%p2]==a) cor[2]++;
    }
    
    vector<int> answer;
    return findMax(answer);
}
