#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

#define MAX_SiZE 50;
using namespace std;

struct Ngaysinh {
int nam[5];
int thang[3];
int ngay[3];
}Ngay;

struct Sinhvien{
char Masv[20];
char Hoten[50];
Ngay Ngaysinh;
char gioitinh[10];
float Diemtb;
} Sinhvien;

vector<Sinhvien> DanhsachSV;

bool kiemTraRong(){
if (danhSachSV.empty()){
   count <<  "\n Danh sachh sinh vien rong. " << endl;
   return true;
  }
  return false;
}

void hienthithongtin() const {
 cout << left
      << setw(30) << fullname
}


int main()
{

    cout << "Hello world!" << endl;
    return 0;
}
