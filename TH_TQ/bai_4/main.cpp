#include <iostream>

using namespace std;

int main(){
    string hovaten;
    float toan,van,tin,diemtb;
    cout<<"Nhap Ho va ten:";
    getline(cin,hovaten);
    cout<<"Nhap diem Toan:";
    cin>>toan;
    cout<<"Nhap diem Van:";
    cin>>van;
    cout<<"Nhap diem Tin:";
    cin>>tin;
    diemtb=(toan+van+tin)/3;
    if(diemtb<5){
        cout<<"Điem trung binh là:"<<diemtb<<"|Xep loai: Yeu";
    } else if(diemtb>=5 && diemtb<7){
          cout<<"Điem trung binh la:"<<diemtb<<"|Xep loai: Trung Binh";
    } else if(diemtb>=7 && diemtb<8){
          cout<<"Điem trung binh la:"<<diemtb<<"|Xep loai: Kha";
    } else if(diemtb>=8){
          cout<<"Diem trung binh la:"<<diemtb<<"|Xep loai: Gioi";
    }
    return 0;
}

