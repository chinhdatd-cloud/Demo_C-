#include <iostream>
#include <stdio.h>
#include <stdbool.h>

using namespace std;

void Nhapmang(int a[], int n){
    for (int i = 0; i < n; i++){
        printf("Nhap phan tu thu d: ", i + 1);
        scanf("%d", &a[i]);
    }
}
void Xuatmang(inta[], int n){
    printf("Mang vua nhap la: ");
    for(int i = 0; i < n; i++){
        printf("%d", a[i]);
    }
 printf("\n");
}

bool Lasonguyento(int x){
    if (x < 2) return false;
    for (int i = 2; i < x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

void Xuatsonguyento(int a[], int n){
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < n; i++){
        if (Lasonguyento(a[i])) printf("%d", a[i]);
    }
printf("\n");
}

bool Lasochinhphuong(int x){
    int r = sqrt(x);
    return r * r == x;
}

void Xuatsochinhphuong(int a[], int n){
    printf("Cac so chinh phuong trong mang: ");
    for (int i = 0; i < n; i++){
        if (Lasochinhphuong(a[i])) printf("%d", a[i]);
    }
printf("\n");
}

bool Lasodoixung(int a[], int n){
    for(int i=0; i < n/2; i++){
        if(a[i] != a[n-1-i]) return false;
    }
    return true;
}

bool Lasotangdan(int a[], int n){
    for (int i = 0; i < n; i++){
        if (a[i] > a[i+1]) return false;
    }
return true;
}

bool Lasogiandan(int a[], int n){
    for(int i = 0; i < n - 1;i++){
        if(a[i] < a[i+ 1]) return false;
    }
    return true;
}

void Timkiemphantu(int a[], int n, int k){
    int found = 0;
    for (int i = n-1; i>=0; i--){
        if (a[i] == k){
            printf("So %d xuat hien 0 vi tri %d \n", k, i);
            found = 1;
        }
    }
if (!found) printf("So %d khong co trong mang! \n ", k);
}

void Sapxepmangtangdan(int a[], int n){
    for (int = 0; i<n-1; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i] > a[j]){
                int temp = a[i];
                a[i]= a[j];
                a[j]= temp;
            }
        }
    }
}
int main()
{
 int n;
printf("Nhap so luong phan tu cua mang: ");
scanf("%d", &n);

int a[100];
nhapMang(a, n);
printf("\n--- Ket qua ---\n");
Xuatmang(a, n);
Xuatsonguyento(a, n);
Xuatsochinhphuong(a, n);

printf("Mang %s doi xung\n", Lasodoixung(a, n) ? "la" : "khong la");
if (Lasogiandan(a, n))
    printf("Mang tang dan\n");
    else if (Lasogiandan(a, n))
        printf("Mang giam dan\n");
    else
        printf("Mang khong tang cung khong giam\n");

int k;
printf("Nhap so nguyen k can tim: ");
scanf("%d", &k);
Timkiemphantu(a, n, k);

Sapxepmangtangdan(a, n);
printf("Mang sau khi sap xep tang dan: ");
Xuatmang(a, n);
}
