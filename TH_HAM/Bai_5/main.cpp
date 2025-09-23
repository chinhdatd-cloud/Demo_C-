#include <iostream>
using namespace std;

long long GiaiThuaKep(int n) {
    long long gt = 1;
    for (int i = n; i > 1; i -= 2) {
        gt *= i;
    }
    return gt;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    cout << n << "!! = " << GiaiThuaKep(n) << endl;

    return 0;
}
