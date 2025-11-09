#include <iostream>
#include <stdio.h>

using namespace std;

int Demphantulon(int a[], int n){
    int dem = 0;
    for (int i = 0; i<n; i++){
        if (i==0 || a[i] > a[i-1]){
            dem++;
        }
    }
return dem;
}

void  Xulytest(){
    int n;
    scanf("%d", &n);
    int a[100];
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printf("%d\n", Demphantulon(a,n));
}

int main()
{
    int t;
    printf("Nhap so bo test: ");
    scanf("%d", &t);

    while (t--) {
        Xulytest();
    }

    return 0;
}
