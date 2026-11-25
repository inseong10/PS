#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int getWeight(int pick, const string& mine){
    if(pick == 0){
        return 1;
    }
    else if(pick == 1){
        if(mine == "diamond") return 5;
        return 1;
    }
    else{
        if(mine == "diamond") return 25;
        if(mine == "iron") return 5;
        return 1;
    }
}

int getVal(const string& s){
    if(s == "diamond") return 25;
    if(s == "iron") return 5;
    return 1;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int limit = min(picks[0]+picks[1]+picks[2], int((minerals.size()+4)/5));
    
    vector<pair<int, int>> group;
    for(int i=0; i<limit; i++){
        int val = 0;
        for(int j=i*5; j<i*5+5; ++j){
            if(j >= minerals.size())    break;
            val += getVal(minerals[j]);
        }
        group.push_back({val, i});
    }
    sort(group.begin(), group.end(), [](pair<int, int>a, pair<int, int> b){return a.first>b.first;});
    
    int choose = 0;
    for(auto p : group){
        while(choose < 3 && !picks[choose]) choose++;
        if(choose >= 3) break;
        
        int idx = p.second;
        int curPick = choose;

        for(int i=idx*5; i<idx*5+5; ++i){
            if(i >= minerals.size())    break;
            answer += getWeight(curPick, minerals[i]);
        }
        picks[choose]--;
        
    }
    
    return answer;
}