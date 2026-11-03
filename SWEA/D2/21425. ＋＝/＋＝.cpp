#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        long long x, y, n;
        cin >> x >> y >> n;

        int count = 0;

        while (x <= n && y <= n) {
            if (x > y) {
                y += x;
            } else {
                x += y;
            }
            ++count;
        }

        cout << count << '\n';
    }

    return 0;
}