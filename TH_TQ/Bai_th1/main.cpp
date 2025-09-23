#include <iostream>
#include <string>
using namespace std;

int main() {
    string tenMatHang, maChatLuong;
    float trongLuong, donGia;
    int soLuong;
    cout << "Nhap ten mat hang: ";
    getline(cin, tenMatHang);

    cout << "Nhap trong luong (kg): ";
    cin >> trongLuong;

    cout << "Nhap don gia (VND): ";
    cin >> donGia;

    cout << "Nhap ma chat luong: ";
    cin >> maChatLuong;

    cout << "Nhap so luong: ";
    cin >> soLuong;

    cout << "\n--- THONG TIN MAT HANG ---\n";
    cout << "Ten mat hang   : " << tenMatHang << endl;
    cout << "Trong luong    : " << trongLuong << " kg" << endl;
    cout << "Don gia        : " << donGia << " VND" << endl;
    cout << "Ma chat luong  : " << maChatLuong << endl;
    cout << "So luong       : " << soLuong << endl;

    return 0;
}
