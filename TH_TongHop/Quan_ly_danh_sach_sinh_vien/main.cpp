#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;


struct NgaySinh {
    int ngay;
    int thang;
    int nam;
};


struct SinhVien {
    string hoTen;
    NgaySinh ngaySinh;
    string gioiTinh;
    float diemTB;
    char maLop[20];
};

void themSinhVien(vector<SinhVien> &ds) {
    SinhVien sv;

    cout << "\n--- Nhap Thong Tin Sinh Vien ---" << endl;
    cout << "Nhap ho ten: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, sv.hoTen);

    cout << "Nhap gioi tinh: ";
    getline(cin, sv.gioiTinh);

    cout << "Nhap diem trung binh: ";
    cin >> sv.diemTB;

    cout << "--- Nhap Ngay Sinh ---" << endl;
    cout << "Nhap Nam sinh (yyyy): ";
    cin >> sv.ngaySinh.nam;
    cout << "Nhap Thang sinh (mm): ";
    cin >> sv.ngaySinh.thang;

    cout << "Nhap Ngay sinh (dd): ";
    cin >> sv.ngaySinh.ngay;

    strcpy(sv.maLop, "CNTT-K65");

    ds.push_back(sv);

    cout << "\n==> Da them sinh vien thanh cong! Ma lop: " << sv.maLop << " ===" << endl;
}

void hienThiDanhSach(const vector<SinhVien> &ds) {
    if (ds.empty()) {
        cout << "\nDanh sach sinh vien rong!" << endl;
        return;
    }

    cout << "\n--- Danh Sach Sinh Vien ---" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << left;
    cout << setw(5) << "STT"
         << setw(25) << "Ho Ten"
         << setw(15) << "Ngay Sinh"
         << setw(15) << "Ma Lop"
         << setw(10) << "Gioi Tinh"
         << setw(10) << "Diem TB" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < ds.size(); ++i) {
        cout << setw(5) << (i + 1)
             << setw(25) << ds[i].hoTen;
        string ngaySinhFormatted =
            (ds[i].ngaySinh.ngay < 10 ? "0" : "") + to_string(ds[i].ngaySinh.ngay) + "/" +
            (ds[i].ngaySinh.thang < 10 ? "0" : "") + to_string(ds[i].ngaySinh.thang) + "/" +
            to_string(ds[i].ngaySinh.nam);
        cout << setw(15) << ngaySinhFormatted;

        cout << setw(15) << ds[i].maLop // In ra mã lớp
             << setw(10) << ds[i].gioiTinh
             << setw(10) << fixed << setprecision(2) << ds[i].diemTB << endl;
    }
    cout << "----------------------------------------------------------------------------------" << endl;
}

void xoaSinhVien(vector<SinhVien> &ds) {
    if (ds.empty()) {
        cout << "\nDanh sach rong, khong co gi de xoa." << endl;
        return;
    }

    string tenCanXoa;
    cout << "\nNhap ten sinh vien can xoa: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, tenCanXoa);

    for (int i = 0; i < ds.size(); ++i) {
        if (ds[i].hoTen.find(tenCanXoa) != string::npos) {
            cout << "Da tim thay: " << ds[i].hoTen << ". Ban co chac chan muon xoa? (y/n): ";
            char xacNhan;
            cin >> xacNhan;

            if (xacNhan == 'y' || xacNhan == 'Y') {
                ds.erase(ds.begin() + i);
                cout << "\n==> Da xoa sinh vien thanh cong! ===" << endl;
                return;
            } else {
                cout << "Huy xoa." << endl;
                return;
            }
        }
    }
    cout << "\nKhong tim thay sinh vien voi ten: " << tenCanXoa << endl;
}

void suaThongTin(vector<SinhVien> &ds) {
    if (ds.empty()) {
        cout << "\nDanh sach rong, khong co gi de sua." << endl;
        return;
    }

    string tenCanSua;
    cout << "\nNhap ten sinh vien can sua: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, tenCanSua);

    for (int i = 0; i < ds.size(); ++i) {
        if (ds[i].hoTen.find(tenCanSua) != string::npos) {
            cout << "Da tim thay sinh vien: " << ds[i].hoTen << endl;
            cout << "--- Nhap Thong Tin Moi (De trong neu khong muon doi) ---" << endl;

            string tempStr;

            cout << "Nhap ho ten moi: ";
            getline(cin, tempStr);
            if (!tempStr.empty()) ds[i].hoTen = tempStr;

            cout << "Nhap gioi tinh moi: ";
            getline(cin, tempStr);
            if (!tempStr.empty()) ds[i].gioiTinh = tempStr;

            cout << "Nhap diem trung binh moi (nhap so): ";
            cin >> ds[i].diemTB; // Sửa điểm

            cout << "--- Sua Ngay Sinh ---" << endl;
            cout << "Nhap Nam sinh moi: ";
            cin >> ds[i].ngaySinh.nam;
            cout << "Nhap Thang sinh moi: ";
            cin >> ds[i].ngaySinh.thang;
            cout << "Nhap Ngay sinh moi: ";
            cin >> ds[i].ngaySinh.ngay;
            cout << "\n==> Da cap nhat thong tin thanh cong! ===" << endl;
            return;
        }
    }
    cout << "\nKhong tim thay sinh vien voi ten: " << tenCanSua << endl;
}

void timKiemSinhVien(const vector<SinhVien> &ds) {
    if (ds.empty()) {
        cout << "\nDanh sach rong." << endl;
        return;
    }

    int luaChon;
    cout << "\n--- Tim Kiem Theo ---" << endl;
    cout << "1. Tim theo ten." << endl;
    cout << "2. Tim theo khoang diem trung binh." << endl;
    cout << "Chon: ";
    cin >> luaChon;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool timThay = false;
    if (luaChon == 1) {
        string tenCanTim;
        cout << "Nhap ten can tim: ";
        getline(cin, tenCanTim);
        for (const auto &sv : ds) {
            if (sv.hoTen.find(tenCanTim) != string::npos) {
                cout << " - " << sv.hoTen << " | Diem: " << sv.diemTB << endl;
                timThay = true;
            }
        }
    } else if (luaChon == 2) {
        float diemMin, diemMax;
        cout << "Nhap khoang diem tu: "; cin >> diemMin;
        cout << "Den: "; cin >> diemMax;
        for (const auto &sv : ds) {
            if (sv.diemTB >= diemMin && sv.diemTB <= diemMax) {
                cout << " - " << sv.hoTen << " | Diem: " << sv.diemTB << endl;
                timThay = true;
            }
        }
    }
    if (!timThay) cout << "Khong tim thay ket qua." << endl;
}

bool soSanhDiem(const SinhVien &a, const SinhVien &b) {
    return a.diemTB > b.diemTB;
}
bool soSanhTen(const SinhVien &a, const SinhVien &b) {
    return a.hoTen < b.hoTen;
}

void sapXepDanhSach(vector<SinhVien> &ds) {
    if (ds.empty()) {
        cout << "\nDanh sach rong." << endl; return;
    }
    int luaChon;
    cout << "\n--- Sap Xep Danh Sach ---" << endl;
    cout << "1. Sap xep theo diem trung binh (Giam dan)." << endl;
    cout << "2. Sap xep theo ten (A-Z)." << endl;
    cout << "Chon: ";
    cin >> luaChon;

    if (luaChon == 1) {
        sort(ds.begin(), ds.end(), soSanhDiem);
        cout << "\n==> Da sap xep theo diem giam dan. ===" << endl;
    } else if (luaChon == 2) {
        sort(ds.begin(), ds.end(), soSanhTen);
        cout << "\n==> Da sap xep theo ten A-Z. ===" << endl;
    } else {
        cout << "Lua chon khong hop le." << endl; return;
    }
    hienThiDanhSach(ds);
}


char* timVaTraVeMaLop(vector<SinhVien> &ds, string tenCanTim) {
    for (int i = 0; i < ds.size(); ++i) {
        if (ds[i].hoTen.find(tenCanTim) != string::npos) {
            return ds[i].maLop;
        }
    }
    return NULL;
}

int main() {
    vector<SinhVien> danhSachSV;
    int luaChon;

    do {
        cout << "\n======================================";
        cout << "\nCHUONG TRINH QUAN LY SINH VIEN (C++)";
        cout << "\n======================================";
        cout << "\n1. Them sinh vien";
        cout << "\n2. Hien thi danh sach sinh vien";
        cout << "\n3. Xoa sinh vien";
        cout << "\n4. Sua thong tin sinh vien";
        cout << "\n5. Tim kiem sinh vien";
        cout << "\n6. Sap xep danh sach";
        cout << "\n7. Kiem tra Ma Lop (Test ham return char*)";
        cout << "\n0. Thoat chuong trinh";
        cout << "\n--------------------------------------";
        cout << "\nLua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: themSinhVien(danhSachSV); break;
            case 2: hienThiDanhSach(danhSachSV); break;
            case 3: xoaSinhVien(danhSachSV); break;
            case 4: suaThongTin(danhSachSV); break;
            case 5: timKiemSinhVien(danhSachSV); break;
            case 6: sapXepDanhSach(danhSachSV); break;
            case 7:
            {
                if (danhSachSV.empty()) {
                    cout << "Danh sach rong, hay them sinh vien truoc." << endl;
                    break;
                }
                cout << "\nNhap ten sinh vien can tim ma lop: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string ten;
                getline(cin, ten);

                char* maLopCuaSV = timVaTraVeMaLop(danhSachSV, ten);

                if (maLopCuaSV != NULL) {
                    cout << "==> Ma lop (kieu char*) da tim thay: " << maLopCuaSV << endl;
                } else {
                    cout << "==> Khong tim thay sinh vien." << endl;
                }
                break;
            }
            case 0:
                cout << "\nCam on ban da su dung chuong trinh!" << endl;
                break;
            default:
                cout << "\nLua chon khong hop le. Vui long chon lai." << endl;
        }
    } while (luaChon != 0);

    return 0;
}
