#include <string>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    string answer = "";


    //step 1
    for(char& c:new_id)
        c = tolower(c);

    //step 2
    for(char c:new_id){
        if(c!='-'&& c!='_' && c!='.' && !('a'<=c&&c<='z') && !('0'<=c&&c<='9'))
            continue;
        answer.push_back(c);
    }

    //step 3
    int pos = 0;
    string points = "..";

    while((pos = answer.find(points, pos)) != std::string::npos){
        answer.replace(pos, points.length(), ".");
    }

    //step4
    if(!answer.empty()&&answer.at(0)=='.'){
        answer.erase(0,1);
    }
    if(!answer.empty()&&answer.at(answer.size()-1)=='.'){
        answer.erase(answer.length()-1,1);
    }

    //step5
    if(answer.empty()) answer="a";

    //step6
    if(answer.length()>15){
        answer.erase(15, answer.length()-15);
    }
    if(answer.at(answer.size()-1)=='.'){
        answer.erase(answer.length()-1,1);
    }


    //step7
    if(answer.length()<=2){
        answer.append(3-answer.length(), answer[answer.length()-1]);
    }
    return answer;
}
int main() {
    string answer = solution("=.=");

    printf("%s", &answer);

    return 0;
}
