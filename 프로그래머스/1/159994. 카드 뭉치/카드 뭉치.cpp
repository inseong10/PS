#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int idx1 = 0, idx2 = 0;
    for(auto s : goal){
        if(cards1[idx1] == s){
            idx1++;
            continue;
        }
        else if(cards2[idx2] == s){
            idx2++;
            continue;
        }
        return "No";
    }
    
    return "Yes";
    
    return answer;
}