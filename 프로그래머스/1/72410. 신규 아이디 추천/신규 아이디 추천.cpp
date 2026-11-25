#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string hw = "hello world";
    
    //1단계
    for(int i=0; i<new_id.size(); ++i){
        new_id[i] = tolower(new_id[i]);
    }

    
    //2단계
    string new_id2;
    for(int i=0; i<new_id.size(); ++i){
        if((new_id[i] <= 'z' && new_id[i] >= 'a') || (new_id[i] >= '0' && new_id[i] <= '9') ||
          new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            new_id2 += new_id[i];
    }
    
    //3단계
    string new_id3;
    for(int i=0; i<new_id2.size(); ++i){
        if(new_id2[i]!='.' || new_id3.empty() || new_id3.back()!='.')
            new_id3.push_back(new_id2[i]);
    }
    
    //4단계
    if(new_id3[0] == '.')   new_id3.erase(0,1);
    if(new_id3[new_id3.size()-1] == '.') new_id3.erase(new_id3.size()-1, 1);
    
    cout << new_id3 << endl; 
    //5단계
    if(new_id3.empty()) new_id3 = "a";
    
    //6단계
    if(new_id3.size() >= 16)    new_id3 = new_id3.substr(0,15);

    if(new_id3[new_id3.size()-1] == '.') new_id3.erase(new_id3.size()-1, 1);
    
    //7단계
    if(new_id3.size() <= 2){
        while(new_id3.size() != 3){
            new_id3 += new_id3.back();
        }
    }

    
    cout << new_id3;
    
    return new_id3;
}