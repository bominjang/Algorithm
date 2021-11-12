#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int solution(string name) {
    int answer = 0;
    
    unordered_map<char, int> alpha;
    
    //A~M
    for(int i=0;i<13;i++)
        alpha['A'+i] = i;
    //N~Z
    for(int j=13;j<26;j++)
        alpha['A'+j] = 26-j;
    
    //left : 'index'로부터 왼쪽 방향으로 갈 때, 'A'가 아닌 알파벳 까지의 거리
    //right : `index`로부터 오른쪽 방향으로 갈 때, `A`가 아닌 알파벳까지의 거리
    //index : 현재 'name'을 가리키고 있는 위치
    int left=0, right=0, index = 0;
    
    while(true)
    {
        //name[index]로 변경하기 위해 눌러야하는 조이스틱의 횟수를 answer에 더해줌
        answer += alpha[name[index]];
        name[index] = 'A';//계산했으므로 바꿔줌
        
        //이제 변경해야하는 다른 문자들 탐색.
      
        //현재 위치의 오른쪽으로 탐색
        for(int i=index+1, count = 1; count < name.length(); i++, count++){
            if(i >= name.length())
                i=0;
            if(name[i] != 'A'){
                //오른쪽으로 이동할 시, 이만큼 이동해야합니다.
                right = count;
                break;
            }
        }
        //현재 위치의 왼쪽으로 탐색
        for(int i=index-1, count=1; count<name.length(); i--, count++){
            if(i<0)
                i=name.length()-1;
            if(name[i]!='A')
            {
                left = count;
                break;
            }
        }
        //left로 가는 거리가 더 짧으면 answer에 추가해주고 index조정
        if(left < right){
            answer+=left;
            index = index-left;
            if(index<0)
                index+=name.length();
        }
        //right로 가는 거리가 더 짧으면 answer에 추가해주고 index조정
        else{
            answer+=right;
            index = index+right;
            if(index>=name.length())
                index -= name.length();
        }
        //전부 다 처리했을 때 break;
        if(right==0 || left == 0)
            break;
        
        right = 0;
        left = 0;
    }
    
    return answer;
}

//ref : https://ansohxxn.github.io/programmers/kit23/
