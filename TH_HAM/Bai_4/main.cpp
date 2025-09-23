#include <iostream>

using namespace std;


double tinhTienTietKiem(double tienGoc, int soThang, double laiSuatThang) {
    for (int i = 1; i <= soThang; i++) {
        tienGoc += tienGoc * laiSuatThang / 100;
    }
    return tienGoc;
}

int main() {
    double tienGoc, laiSuatThang;
    int soThang;

    cout << "Nhap so tien gui ban dau (VND): ";
    cin >> tienGoc;
    cout << "Nhap so thang gui: ";
    cin >> soThang;
    cout << "Nhap lai suat 1 thang (%): ";
    cin >> laiSuatThang;

    double tongTien = tinhTienTietKiem(tienGoc, soThang, laiSuatThang);
    cout << "Tong so tien sau " << soThang << " thang la: " << tongTien << " VND" << endl;

    return 0;
}
