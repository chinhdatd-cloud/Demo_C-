#include <iostream>
#include <stdio.h>

using namespace std;
void Timsoxuauthiennhieunhat(int a[], int n){
    int Tansuat[30001] = {0};
    int max = 0;
    for (int i=0; i<n; i++){
        Tansuat[a[i]]++;
        if(Tansuat[a[i]] > max) max = Tansuat[a[i]];
    }

    for(int i = 0; i<n; i++){
        if (Tansuat[a[i]] == max){
            printf("%d", a[i]);
            Tansuat[a[i]] = 0;
        }
}
print("%d");
}

void Xulytest(){
    int n;
    scanf("%d", &n);
    int a[100];
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    Timsoxuauthiennhieunhat(a,n);

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
