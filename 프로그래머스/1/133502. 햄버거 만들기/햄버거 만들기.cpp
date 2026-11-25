#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> burger;
    
    for(auto v : ingredient){
        burger.push_back(v);
        int cnt = burger.size();
        
        if(cnt>=4 && burger[cnt-1]==1 && burger[cnt-2]==3 && burger[cnt-3]==2 && burger[cnt-4]==1){
            answer++;
            for(int i=0;i<4;++i)
                burger.pop_back();
        }
    }
    
    return answer;
}