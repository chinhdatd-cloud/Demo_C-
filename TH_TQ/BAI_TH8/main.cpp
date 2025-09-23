#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    bool laSNT = true ;

    cout<< "Nhap mot so nguyen: ";
    cin >> n;
    if (n < 2){
        laSNT = false;
    } else {
        for(int i = 2; i <= sqrt(n); ++i){
            if (n % i == 0){
                laSNT = false;
                break;
            }
        }
    }
   cout << boolalpha;
   if (laSNT) {
    cout<< n << "LA so nguyen to: " << endl;
   } else {
    cout<< n << "Khong la so nguyen to: " << endl;
   }
   return 0;
}
