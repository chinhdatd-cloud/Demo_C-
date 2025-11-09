#include <iostream>
#include <stdio.h>

using namespace std;

int Demcapbangnhau(int a[], int n){
    int dem = 0;
    for (int i = 0; i < n-1; i++){
        if (a[i] == a[i+1]){
            dem++;
        }
    }
return dem;
}

void Xulytest(){
    int n;
    scanf("%d",&n);
    int a[100];
    for (int i=0; i < n; i++){
        scanf("%d", &a[i]);
    }
int kq = Demcapbangnhau(a,n);
printf("%d\n", kq);
}
int main()
{
    int t;
    printf("Nhap so bo test: ");
    scanf("%d", &t);

    int t;
    printf("Nhap so bo test: ");
    scanf("%d", &t);

    while (t--) {
        Xulytest();
    }
    return 0;
}
