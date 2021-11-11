#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> chat; //id, func저장
    unordered_map<string, string> people;
    
    for(int i=0; i<record.size(); i++){
        string toki[3];
        string token;
        stringstream ss(record[i]);
        int idx = 0;
        
        while (ss >> token) {
            toki[idx++] = token;
        }
        
        string func = toki[0];
        string id = toki[1];
        string nick = toki[2];
        
        if(func!="Change"){
            chat.push_back({id, func});
        }
        if(func!="Leave"){
            people[id] = nick;
        }
    }
    
    for(int i=0;i<chat.size();i++){
        string nick = people[chat[i].first];
        string func = chat[i].second;
        string msg = "";
        if(func == "Enter") msg = nick+"님이 들어왔습니다.";
        else if(func=="Leave") msg= nick +"님이 나갔습니다.";
        answer.push_back(msg);
    }
    return answer;
}
