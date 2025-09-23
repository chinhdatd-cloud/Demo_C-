#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double Tiengui , Laisuat;
    int thang;

    cout<< "Nhap so tien gui ban dau: "; cin>> Tiengui;
    cout<< "Nhap so thang gui: "; cin >> thang;
    cout<< "Nhap lai suat hang thang (Duoi dang phan tram , VD: 2.2): "; cin >> Laisuat;

    for(int i=1; i <= thang; ++i){
        Tiengui = Tiengui + (Tiengui * Laisuat / 100.0);
    }
    cout << fixed << setprecision(2);
    cout<< "So tien co duoc sau " << thang << "thang la: " << Tiengui << endl;

    return 0;
}
