#include <iostream>

using namespace std;

int twoTile (int x) {
    int returnVal;
    if (x == 2) {
        return 3;
    }
    else if (x == 1) {
        return 1;
    }
    return twoTile(x - 1) + 2*twoTile(x - 2);
}

int main () {
    int iterations = 10;
    //cout << twoTile(iterations) << "\n";
    int n = 10;
    int x1 = 1;
    int x2 = 3;
    int x = 0;
    for (int i = 2; i <= n; i++) {
        x = x2 + 2 * x1;
        x1 = x2;
        x2 = x;
        cout << x << "\n";
    }

}









































