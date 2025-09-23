#include <iostream>

using namespace std;

int main() {
    int Sobotest;
    cout << "Nhap so bo test: ";
    cin >> Sobotest;

    for (int t = 0; t < Sobotest; t++) {
        int Sotien;
        cout << "Nhap so tien can tra: ";
        cin >> Sotien;

        int Sotien10 = Sotien / 10;
        Sotien %= 10;
        int Sotien5 = Sotien / 5;
        int Sotien1 = Sotien % 5;

        cout << (Sotien10 * 10 + Sotien5 * 5 + Sotien1) << " = "
             << Sotien10 << "*10 + "
             << Sotien5 << "*5 + "
             << Sotien1 << "*1" << endl;
    }

    return 0;
}
