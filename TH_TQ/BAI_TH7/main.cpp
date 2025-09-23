#include <iostream>
using namespace std;
int main()
{
double tienGui, laiSuat, tienNhan;
int thang=0;
cout<<"Nhap tien gui:";
cin>>tienGui;
cout<<"Lai suat:";
cin>>laiSuat;
cout<<"Nhap tien nhan:";
cin>>tienNhan;
while(tienGui<tienNhan){
    tienGui=tienGui+(tienGui*laiSuat)/100;
    thang++;
}
cout<<"So thang gui la: "<<thang;
}
