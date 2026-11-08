#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    vector<int> st;
    st.reserve(ingredient.size());

    int answer = 0;

    for (int value : ingredient) {
        st.push_back(value);

        int n = st.size();

        if (n >= 4 &&
            st[n - 4] == 1 &&
            st[n - 3] == 2 &&
            st[n - 2] == 3 &&
            st[n - 1] == 1) {

            for (int i = 0; i < 4; ++i) {
                st.pop_back();
            }

            ++answer;
        }
    }

    return answer;
}