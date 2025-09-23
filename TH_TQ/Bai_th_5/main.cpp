#include <iostream>

using namespace std;
int main(){
    double diemThang10;
    cout << "Nhap diem cua ban theo thang diem 10: ";
    cin >> diemThang10;
    double diemThang4;
    char thangChu;
    if (diemThang10 >= 9.0) {
        diemThang4 = 4.0;
        thangChu = 'A';
    } else if (diemThang10 >= 8.0) {
        diemThang4 = 3.5;
        thangChu = 'A';
    } else if (diemThang10 >= 7.0) {
        diemThang4 = 3.0;
        thangChu = 'B';
    } else if (diemThang10 >= 6.0) {
        diemThang4 = 2.5;
        thangChu = 'B';
    } else if (diemThang10 >= 5.0) {
        diemThang4 = 2.0;
        thangChu = 'C';
    } else if (diemThang10 >= 4.0) {
        diemThang4 = 1.5;
        thangChu = 'D';
    } else {
        diemThang4 = 1.0;
        thangChu = 'F';
    }
   cout << "\nKet qua chuyen doi:\n";
    cout << "Diem thang 4: " << diemThang4 << endl;
    cout << "Diem chu: " << thangChu << endl;
    return 0;
}
