#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    int i = 0;
    for(; i<completion.size(); ++i){
        if(completion[i] != participant[i]){
            answer = participant[i];
            break;
        }
    }
    if(i == completion.size())  answer = participant.back();
    
    return answer;
}