#include <iostream>
#include <cmath>
using namespace std;

int SoThangGui(double Sotienbandau, double Sotiencandang, double Laisuat) {
    int thang = 0;
    double sotien = Sotienbandau;
    while (sotien < Sotiencandang) {
        sotien *= (1 + Laisuat);
        thang++;
    }
    return thang;
}

int main() {
    double Sotienbandau, Sotiencandang, Laisuat;
    cout << "Nhap so tien ban dau: ";
    cin >> Sotienbandau;
    cout << "Nhap so tien can dat duoc: ";
    cin >> Sotiencandang;
    cout << "Nhap lai suat 1 thang (theo %): ";
    cin >> Laisuat;

    Laisuat = Laisuat / 100.0;

    int thang = SoThangGui(Sotienbandau, Sotiencandang, Laisuat);
    cout << "So thang gui it nhat: " << thang << endl;

    return 0;
}
