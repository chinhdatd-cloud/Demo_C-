#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cstring>

 #define MAX_SiZE 50;
using namespace std;


struct NgaySinh {
    int ngay[3 ];
    int thang[3];
    int nam[5];
};


struct Sinhvien {
    char hoten[30];
    NgaySinh ngaysinh;
    char gioitinh[5];
    float diemtb;
    char malop[20];
};

void Themsinhvien(vector<Sinhvien> &ds) {
    Sinhvien sv;

    cout << "\n--- Nhap Thong Tin Sinh Vien ---" << endl;
    cout << "Nhap ho ten: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(sv.hoten, 30);

    cout << "Nhap gioi tinh: ";
    cin.getline(sv.gioitinh, 5);
    cout << "Nhap diem trung binh: ";
    cin >> sv.diemtb;

    cout << "--- Nhap Ngay Sinh ---" << endl;
    cout << "Nhap Nam sinh (yyyy): ";
    cin >> sv.ngaysinh.nam;
    cout << "Nhap Thang sinh (mm): ";
    cin >> sv.ngaysinh.thang;

    cout << "Nhap Ngay sinh (dd): ";
    cin >> sv.ngaysinh.ngay;
    strcpy(sv.malop, "CNTT-K47C");

    ds.push_back(sv);

    cout << "\n==> Da them sinh vien thanh cong! Ma lop: " << sv.malop << " ===" << endl;
}

void Hienthidanhsach(const vector<Sinhvien> &ds) {
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
             << setw(25) << ds[i].hoten;
        string ngaysinhFormatted =
            (ds[i].ngaysinh.ngay < 10 ? "0" : "") + to_string(ds[i].ngaysinh.ngay) + "/" +
            (ds[i].ngaysinh.thang < 10 ? "0" : "") + to_string(ds[i].ngaysinh.thang) + "/" +
            to_string(ds[i].ngaysinh.nam);
        cout << setw(15) << ngaysinhFormatted;

        cout << setw(15) << ds[i].malop
             << setw(10) << ds[i].gioitinh
             << setw(10) << fixed << setprecision(2) << ds[i].diemtb << endl;
    }
    cout << "----------------------------------------------------------------------------------" << endl;
}

void Xoasinhvien(vector<Sinhvien> &ds) {
    if (ds.empty()) {
        cout << "\nDanh sach rong, khong co gi de xoa." << endl;
        return;
    }

    string tencanxoa;
    cout << "\nNhap ten sinh vien can xoa: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, tencanxoa);

    for (int i = 0; i < ds.size(); ++i) {
        if (strstr(ds[i].hoten, tencanxoa.c_str()) != NULL) {
            cout << "Da tim thay: " << ds[i].hoten << ". Ban co chac chan muon xoa? (y/n): ";
            char xacnhan;
            cin >> xacnhan;

            if (xacnhan == 'y' || xacnhan == 'Y') {
                ds.erase(ds.begin() + i);
                cout << "\n==> Da xoa sinh vien thanh cong! ===" << endl;
                return;
            } else {
                cout << "Huy xoa." << endl;
                return;
            }
        }
    }
    cout << "\nKhong tim thay sinh vien voi ten: " << tencanxoa << endl;
}

void Suathongtin(vector<Sinhvien> &ds) {
    if (ds.empty()) {
        cout << "\nDanh sach rong, khong co gi de sua." << endl;
        return;
    }

    string tencansua;
    cout << "\nNhap ten sinh vien can sua: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, tencansua);

    for (int i = 0; i < ds.size(); ++i) {
        if (strstr(ds[i].hoten, tencansua.c_str()) != NULL) {
            cout << "Da tim thay sinh vien: " << ds[i].hoten << endl;
            cout << "--- Nhap Thong Tin Moi (De trong neu khong muon doi) ---" << endl;

            string tempstr;

            cout << "Nhap ho ten moi: ";
            getline(cin, tempstr);
            if (!tempstr.empty()) {
                strcpy(ds[i].hoten, tempstr.c_str());
            }

            cout << "Nhap gioi tinh moi: ";
            getline(cin, tempstr);
            if (!tempstr.empty()) {
                strcpy(ds[i].gioitinh, tempstr.c_str());
            }

            cout << "Nhap diem trung binh moi (nhap so): ";
            cin >> ds[i].diemtb;

            cout << "--- Sua Ngay Sinh ---" << endl;
            cout << "Nhap Nam sinh moi: ";
            cin >> ds[i].ngaysinh.nam;
            cout << "Nhap Thang sinh moi: ";
            cin >> ds[i].ngaysinh.thang;
            cout << "Nhap Ngay sinh moi: ";
            cin >> ds[i].ngaysinh.ngay;
            cout << "\n==> Da cap nhat thong tin thanh cong! ===" << endl;
            return;
        }
    }
    cout << "\nKhong tim thay sinh vien voi ten: " << tencansua << endl;
}

void Timkiemsinhvien(const vector<Sinhvien> &ds) {
    if (ds.empty()) {
        cout << "\nDanh sach rong." << endl;
        return;
    }

    int luachon;
    cout << "\n--- Tim Kiem Theo ---" << endl;
    cout << "1. Tim theo ten." << endl;
    cout << "2. Tim theo khoang diem trung binh." << endl;
    cout << "Chon: ";
    cin >> luachon;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool timthay = false;
    if (luachon == 1) {
        string tencantim;
        cout << "Nhap ten can tim: ";
        getline(cin, tencantim);
        for (const auto &sv : ds) {
            if (strstr(sv.hoten, tencantim.c_str()) != NULL) {
                cout << " - " << sv.hoten << " | Diem: " << sv.diemtb << endl;
                timthay = true;
            }
        }
    } else if (luachon == 2) {
        float diemmin, diemmax;
        cout << "Nhap khoang diem tu: "; cin >> diemmin;
        cout << "Den: "; cin >> diemmax;
        for (const auto &sv : ds) {
            if (sv.diemtb >= diemmin && sv.diemtb <= diemmax) {
                cout << " - " << sv.hoten << " | Diem: " << sv.diemtb << endl;
                timthay = true;
            }
        }
    }
    if (!timthay) cout << "Khong tim thay ket qua." << endl;
}

bool Sosanhdiem(const Sinhvien &a, const Sinhvien &b) {
    return a.diemtb > b.diemtb;
}
bool Sosanhten(const Sinhvien &a, const Sinhvien &b) {
    return strcmp(a.hoten, b.hoten) < 0;
}

void Sapxepdanhsach(vector<Sinhvien> &ds) {
    if (ds.empty()) {
        cout << "\nDanh sach rong." << endl; return;
    }
    int luachon;
    cout << "\n--- Sap Xep Danh Sach ---" << endl;
    cout << "1. Sap xep theo diem trung binh (Giam dan)." << endl;
    cout << "2. Sap xep theo ten (A-Z)." << endl;
    cout << "Chon: ";
    cin >> luachon;

    if (luachon == 1) {
        sort(ds.begin(), ds.end(), Sosanhdiem);
        cout << "\n==> Da sap xep theo diem giam dan. ===" << endl;
    } else if (luachon == 2) {
        sort(ds.begin(), ds.end(), Sosanhten);
        cout << "\n==> Da sap xep theo ten A-Z. ===" << endl;
    } else {
        cout << "Lua chon khong hop le." << endl; return;
    }
    Hienthidanhsach(ds);
}


char* Timvatravemalop(vector<Sinhvien> &ds, string tencantim) {
    for (int i = 0; i < ds.size(); ++i) {
        if (strstr(ds[i].hoten, tencantim.c_str()) != NULL) {
            return ds[i].malop;
        }
    }
    return NULL;
}

int main() {
    vector<Sinhvien> danhsachsv;
    int luachon;

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
        cin >> luachon;

        switch (luachon) {
            case 1: Themsinhvien(danhsachsv); break;
            case 2: Hienthidanhsach(danhsachsv); break;
            case 3: Xoasinhvien(danhsachsv); break;
            case 4: Suathongtin(danhsachsv); break;
            case 5: Timkiemsinhvien(danhsachsv); break;
            case 6: Sapxepdanhsach(danhsachsv); break;
            case 7:
            {
                if (danhsachsv.empty()) {
                    cout << "Danh sach rong, hay them sinh vien truoc." << endl;
                    break;
                }
                cout << "\nNhap ten sinh vien can tim ma lop: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string ten;
                getline(cin, ten);
                char* Malopcuasv = Timvatravemalop(danhsachsv, ten);
                if (Malopcuasv != NULL) {
                    cout << "==> Ma lop (kieu char*) da tim thay: " << Malopcuasv << endl;
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
    } while (luachon != 0);

    return 0;
}
