#include <string>

using namespace std;

string solution(string s, string skip, int index) {
    bool skipped[26] = {};

    for (char ch : skip) {
        skipped[ch - 'a'] = true;
    }

    for (char& ch : s) {
        int remaining = index;

        while (remaining > 0) {
            ch = (ch == 'z') ? 'a' : ch + 1;

            if (!skipped[ch - 'a']) {
                --remaining;
            }
        }
    }

    return s;
}