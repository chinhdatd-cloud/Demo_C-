#include <iostream>
#include <cmath>

using namespace std;


string LoaiTamGiac(double a, double b, double c) {
    if (a + b <= c || a + c <= b || b + c <= a) return "Khong phai tam giac";
    if (a == b && b == c) return "Tam giac deu";
    if (a == b || b == c || a == c) {
        if (fabs(a*a + b*b - c*c) < 1e-6 || fabs(a*a + c*c - b*b) < 1e-6 || fabs(b*b + c*c - a*a) < 1e-6)
            return "Tam giac vuong can";
        return "Tam giac can";
    }
    if (fabs(a*a + b*b - c*c) < 1e-6 || fabs(a*a + c*c - b*b) < 1e-6 || fabs(b*b + c*c - a*a) < 1e-6)
        return "Tam giac vuong";
    return "Tam giac thuong";
}


double DienTichTamGiac(double a, double b, double c) {
    if (a + b <= c || a + c <= b || b + c <= a) return 0;
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    double a, b, c;
    cout << "Nhap 3 canh tam giac: ";
    cin >> a >> b >> c;

    cout << "Loai tam giac: " << LoaiTamGiac(a, b, c) << endl;
    cout << "Dien tich: " << DienTichTamGiac(a, b, c) << endl;

    return 0;
}
