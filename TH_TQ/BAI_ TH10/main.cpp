#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double Sotiencanco ;
    int Sothanggui ;
    double Laisuat1thang;

    cout << "Nhap so tien can co: ";
    cin >> Sotiencanco;
    cout << "Nhap so thang gui: ";
    cin >> Sothanggui;
    cout << "Nhap lai suat 1 thang (theo phan tram): ";
    cin >> Laisuat1thang;

    Laisuat1thang = Laisuat1thang / 100.0; // đổi % sang dạng thập phân

    double Sotiengoc = Sotiencanco / pow(1 + Laisuat1thang, Sothanggui);
    cout << fixed << setprecision(2);
    cout << "So tien goc it nhat phai gui: " << Sotiengoc << endl;

    return 0;
}
