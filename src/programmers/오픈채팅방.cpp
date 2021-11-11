#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> chat; //id, func저장
    unordered_map<string, string> people; //key : id, val : nickname 저장
    
    for(int i=0; i<record.size(); i++){
        string toki[3];//각 record 들의 function, id, nickname을 저장할 배열
        string token;
        stringstream ss(record[i]);//stringstream에 넣으면 공백을 기준으로 문자열을 잘라줌
        int idx = 0;
        
        while (ss >> token) {//stream에서 하나씩 빼와서 token에 넣어줌.
            toki[idx++] = token;//token을 toki 배열에 저장.
        }
        //알아보기 쉽게 변수를 할당하여 저장
        string func = toki[0];
        string id = toki[1];
        string nick = toki[2];
        //function이 Change가 아닐 때, chat 내용에 남김.
        if(func!="Change"){
            chat.push_back({id, func});//여기서 id와 function을 저장하는 이유는, nickname은 나중에 바뀔 수도 있기 때문!
        }
		//function이 Leave가 아닐 때, 해당 id에 대응하는 nickname 을 map에 저장.
        if(func!="Leave"){
            people[id] = nick;
        }
    }
    //채팅 내용 answer에 추가
    for(int i=0;i<chat.size();i++){
        string nick = people[chat[i].first];//id에 대응하는 nickname
        string func = chat[i].second;//function
        string msg = "";
		//추가
        if(func == "Enter") msg = nick+"님이 들어왔습니다.";
        else if(func=="Leave") msg= nick +"님이 나갔습니다.";
        answer.push_back(msg);
    }
    return answer;
}
