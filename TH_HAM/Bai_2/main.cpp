#include <iostream>
using namespace std;

void QuyDoiDiem(double diem10) {
    double diem4;
    string diemchu;

    if (diem10 >= 9.0) { diem4 = 4.0; diemchu = "A+"; }
    else if (diem10 >= 8.0) { diem4 = 3.5; diemchu = "A"; }
    else if (diem10 >= 7.0) { diem4 = 3.0; diemchu = "B+"; }
    else if (diem10 >= 6.0) { diem4 = 2.5; diemchu = "B"; }
    else if (diem10 >= 5.0) { diem4 = 2.0; diemchu = "C"; }
    else if (diem10 >= 4.0) { diem4 = 1.5; diemchu = "D"; }
    else { diem4 = 0; diemchu = "F"; }

    cout << "Diem thang 4: " << diem4 << endl;
    cout << "Diem chu: " << diemchu << endl;
}

int main() {
    double diem10;
    cout << "Nhap diem thang 10: ";
    cin >> diem10;

    QuyDoiDiem(diem10);

    return 0;
}
