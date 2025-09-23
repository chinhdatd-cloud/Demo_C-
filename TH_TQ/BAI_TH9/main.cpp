#include <iostream>
using namespace std;

int main() {
    int n;
    long long gt = 1;

    cout << "Nhap n: ";
    cin >> n;

    for (int i = n; i > 1; i -= 2) {
        gt *= i;
    }

    cout << n << "!! = " << gt << endl;
    return 0;
}
