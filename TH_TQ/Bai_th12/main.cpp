#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Hàm kiểm tra một số có 6 chữ số có phải là số thuận nghịch không
bool laSoThuanNghich(int so) {
    string chuoi = to_string(so);
    if (chuoi.length() != 6) return false;
    for (int i = 0; i < 3; i++) {
        if (chuoi[i] != chuoi[5 - i]) return false;
    }
    return true;
}

// Hàm tính tổng các chữ số của một số có 6 chữ số
int tinhTongChuSo(int so) {
    int tong = 0;
    while (so > 0) {
        tong += so % 10;
        so /= 10;
    }
    return tong;
}

// Hàm kiểm tra tổng các chữ số có chứa chữ số 0 không
bool coChuaSoKhong(int tong) {
    while (tong > 0) {
        if (tong % 10 == 0) return true;
        tong /= 10;
    }
    return false;
}

// Hàm kiểm tra một số có 6 chữ số có phải là Loại 3 không
bool laLoai3(int so) {
    return laSoThuanNghich(so);
}

// Hàm kiểm tra một số có 6 chữ số có phải là Loại 2 không
bool laLoai2(int so) {
    if (!laLoai3(so)) return false;
    int tong = tinhTongChuSo(so);
    return (tong % 10 == 0);
}

// Hàm kiểm tra một số có 6 chữ số có phải là Loại 1 không
bool laLoai1(int so) {
    if (!laLoai2(so)) return false;
    int tong = tinhTongChuSo(so);
    return !coChuaSoKhong(tong);
}

// Hàm đếm số lượng số thoả mãn từng loại trong khoảng 000000 đến 999999
void demSoLuongMoiLoai(int &demLoai1, int &demLoai2, int &demLoai3) {
    demLoai1 = 0;
    demLoai2 = 0;
    demLoai3 = 0;
    for (int so = 0; so <= 999999; so++) {
        if (laLoai3(so)) {
            demLoai3++;
            if (laLoai2(so)) {
                demLoai2++;
                if (laLoai1(so)) {
                    demLoai1++;
                }
            }
        }
    }
}

int main() {
    int soBoTest;
    cin >> soBoTest;

    int demLoai1, demLoai2, demLoai3;
    demSoLuongMoiLoai(demLoai1, demLoai2, demLoai3);

    while (soBoTest--) {
        int N, M, K;
        cin >> N >> M >> K;

        // Kiểm tra điều kiện phân phối
        if (N <= demLoai1 && M <= demLoai2 - demLoai1 && K <= demLoai3 - demLoai2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
