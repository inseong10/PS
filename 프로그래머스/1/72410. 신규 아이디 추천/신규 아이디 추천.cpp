#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string str = new_id;
    
    for(int i=0; i<new_id.size(); ++i){      
        str[i] = tolower(new_id[i]);
    }
    
    string str2;
    for(auto s : str){
        if((s >= '0' && s <= '9') || (s >= 'a' && s <= 'z') || s == '-' || s == '_' || s == '.')
            str2.push_back(s);
    }
    
    string str3;
    for(auto s : str2){
        if(s != '.' || str3.empty() || str3.back() != '.'){
            str3.push_back(s);
        }
    }
    
    if(!str.empty() && str3.front() == '.')   str3.erase(0, 1);
    if(!str.empty() && str3.back() == '.')  str3.erase(str3.size()-1, 1);
    
    if(str3.empty()) str3 = "a";
    
    if(str3.size() >= 16){
        str3.erase(15, str3.size()-15);
        if(str3.back() == '.')  str3.erase(str3.size()-1, 1);
    }
    
    if(str3.size() <= 2){
        while(str3.size() != 3){
            str3.push_back(str3.back());
        }
    }
    
    cout << str3;

    
    string answer = str3;
    return answer;
}