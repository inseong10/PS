#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    int n = citations.size();
    for(int i=0; i<n; ++i){
        int h = n-i;
        int cur_cit = citations[i];
        
        cout << "h : " << h << " cur citation : " << cur_cit << endl;
        
        if(h <= cur_cit){
            answer = h;
            break;
        }
    }
    
    return answer;
}