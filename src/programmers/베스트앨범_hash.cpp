#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<string, int> si;

map<string, int> hash_map; //장르들의 재생횟수 합을 저장하는 해시맵
map<string, vector<pair<int,int>>> ranking; //key: 장르, value: pair<고유번호, 재생횟수> 타입의 벡터

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second > b.second; //내림차순 정렬
}

bool cmp2(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second; //내림차순 정렬
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector <int> answer;
    
    //hash_map에는 각 장르별 플레이 수 총 합을 저장하고, ranking에는 각 장르의 <고유번호,플레이 횟수>자료형을 벡터에 추가한다.
    for(int i=0;i<genres.size();i++)
    {
        hash_map[genres[i]] += plays[i];
        ranking[genres[i]].push_back({i,plays[i]});
    }
    vector<pair<string, int>> vec(hash_map.begin(), hash_map.end());//map의 value를 정렬하기 위해 map을 vector로 복사한다.
    sort(vec.begin(), vec.end(), cmp);//value들을 내림차순 정렬.
    
    for(si sit:vec){//정렬된 vec를 돌면서 answer에 추가한다.
        string k = sit.first;//장르
        vector<pair<int, int>> v = ranking[k];//해당 장르의 <고유번호, 플레이 횟수>벡터를 복사한다.
        sort(v.begin(), v.end(), cmp2);//해당 벡터를 내림차순 정렬.
        if(v.size()==1){//벡터 사이즈가 1이면 하나만 선택
            answer.push_back(v[0].first);
        }else{//아니라면 2개 선택
            answer.push_back(v[0].first);
            answer.push_back(v[1].first);
        }
    }
    
    return answer;
}
