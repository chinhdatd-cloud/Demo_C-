#include <iostream>
#include <cmath>
using namespace std;

bool LaNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int DemNguyenTo(int m, int n) {
    int dem = 0;
    for (int i = m; i <= n; i++) {
        if (LaNguyenTo(i)) dem++;
    }
    return dem;
}

int main() {
    int m, n;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;

    cout << "So luong so nguyen to trong [" << m << ", " << n << "] la: "
         << DemNguyenTo(m, n) << endl;

    return 0;
}
