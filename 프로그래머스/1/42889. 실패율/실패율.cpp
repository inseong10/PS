#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

double Mycount[200001];
vector<pair<double, int>> failRate;

vector<int> solution(int N, vector<int> stages) {
    
    for(auto v : stages){
        Mycount[v]++;
    }
    
    for(int i=1; i<=N; ++i){
        cout << Mycount[i] << " ";
    }
    cout << endl;
    
    int curN = stages.size();
    for (int i = 1; i <= N; ++i) {
        double rate = (curN == 0)
            ? 0.0
            : static_cast<double>(Mycount[i]) / curN;

        failRate.push_back({rate, i});
        curN -= Mycount[i];
    }
    
    
    sort(failRate.begin(), failRate.end(),
     [](const pair<double, int>& a, const pair<double, int>& b) {
         if (a.first == b.first)
                 return a.second < b.second;
         
         return a.first > b.first;
     });
    
    vector<int> answer;
    for(auto v : failRate){
        answer.push_back(v.second);
    }
    
    return answer;
}