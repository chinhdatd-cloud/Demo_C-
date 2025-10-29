#include <iostream>
using namespace std;

int main() {
    int thang, nam;
    int soNgay = 0;
    cout << "Nhap thang (1-12): ";
    cin >> thang;
    cout << "Nhap nam: ";
    cin >> nam;
    if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
        soNgay = 31;
    } else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        soNgay = 30;
    } else if (thang == 2) {

        if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) {
            soNgay = 29;
        } else {
            soNgay = 28;
        }
    } else {
        soNgay = 0;
    }

    if (soNgay != 0) {
        cout << "Thang " << thang << " nam " << nam << " co " << soNgay << " ngay." << endl;
    } else {
        cout << "Thang khong hop le!" << endl;
    }

    return 0;
}
