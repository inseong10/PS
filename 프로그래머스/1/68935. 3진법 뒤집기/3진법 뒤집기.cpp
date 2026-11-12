#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> v;
    
    while(n > 0){
        v.push_back(n%3);
        n /= 3;
    }
    
    int dec = 0;
    int w = 1;
    
    for(int i=v.size()-1; i>=0; --i){
        dec += v[i]*w;
        w *= 3;
    }
    
    int answer = dec;
    
    
    return answer;
}