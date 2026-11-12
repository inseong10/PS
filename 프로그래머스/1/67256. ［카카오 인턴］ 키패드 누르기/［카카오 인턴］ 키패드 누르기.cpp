#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef struct _node{
    int x;
    int y;
}node;

node StoC(int s){
    int num = s;
    if(s == 0)  return {1, 3};
    
    return {(num-1)%3, (num-1)/3};
}

int cmp(node L, node R, node num){
    int distL = abs(num.x - L.x) + abs(num.y - L.y);
    int distR = abs(num.x - R.x) + abs(num.y - R.y);
    
    if(distL == distR)  return 2;
    
    return distL < distR ? 1 : 0;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    node cL = {0, 3};
    node cR = {2, 3};
    
    for(auto s : numbers){
        if(s == 1 || s == 4 || s == 7){
            answer.push_back('L');
            cL = StoC(s);
        }
        else if(s == 3 || s == 6 || s == 9){
            answer.push_back('R');
            cR = StoC(s);
        }
        
        else{
            int cmd = cmp(cL, cR, StoC(s));
            
            if(cmd == 1){
                answer.push_back('L');
                cL = StoC(s);
            }
            else if(cmd == 0){
                answer.push_back('R');
                cR = StoC(s);
            }
            else{
                if(hand == "left"){
                    answer.push_back('L');
                    cL = StoC(s);
                }
                else{
                    answer.push_back('R');
                    cR = StoC(s);
                }
            }

        }
        //cout << "cL : " << cL.x << " " << cL.y << " cR : " << cR.x << " " << cR.y << endl;
    }
    
    return answer;
}