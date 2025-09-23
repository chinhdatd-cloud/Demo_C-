#include <iostream>
using namespace std;

double TinhTienDien(int sodien) {
    double tien = 0;
    if (sodien <= 100) tien = sodien * 1418;
    else if (sodien <= 150) tien = 100 * 1418 + (sodien - 100) * 1622;
    else if (sodien <= 200) tien = 100 * 1418 + 50 * 1622 + (sodien - 150) * 2044;
    else if (sodien <= 300) tien = 100 * 1418 + 50 * 1622 + 50 * 2044 + (sodien - 200) * 2210;
    else if (sodien <= 400) tien = 100 * 1418 + 50 * 1622 + 50 * 2044 + 100 * 2210 + (sodien - 300) * 2361;
    else tien = 100 * 1418 + 50 * 1622 + 50 * 2044 + 100 * 2210 + 100 * 2361 + (sodien - 400) * 2420;
    return tien;
}

int main() {
    int chisocu, chisomoi;
    cout << "Nhap chi so dien thang truoc: ";
    cin >> chisocu;
    cout << "Nhap chi so dien thang nay: ";
    cin >> chisomoi;

    int sodien = chisomoi - chisocu;
    if (sodien < 0) {
        cout << "Chi so dien khong hop le!" << endl;
    } else {
        cout << "So dien tieu thu: " << sodien << endl;
        cout << "Tien dien phai tra: " << TinhTienDien(sodien) << " VND" << endl;
    }

    return 0;
}
