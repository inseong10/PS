#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> store;
    string answer = "";
    
    for(auto v : numbers){
        store.push_back(to_string(v));
    }
    
    sort(store.begin(), store.end(),
        [](string a, string b){
            return a+b > b+a;
        }
    );
    
    if (store.front() == "0") {
        return "0";
    }
      
    for(auto s : store){
        answer += s;
    }
    
    return answer;
}