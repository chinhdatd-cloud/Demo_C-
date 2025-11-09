#include <iostream>
#include <stdio.h>

using namespace std;

int Tongchuso(int n){
    int tong = 0;
    while (n>0){
        tong += n % 10;
        n /= 10;
    }
return tong;
}

int DemsotongchusobangS(int S){
    int dem = 0;
    for (int i = 1000; i<= 99999; i++){
        if (Tongchuso(i) == S) dem++;
    }
return dem;
}
int main()
{
int t;
    printf("Nhap so bo test: ");
    scanf("%d", &t);

    while (t--) {
        int S;
        scanf("%d", &S);
        printf("%d\n", Demtongchubangs(S));
    }
    return 0;
}
