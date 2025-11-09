#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Sach{
char Masach[20];
char Tensach[50];
char Tacgia[50];
int Soluong;
};

void Nhapsach(struct Sach *s){
    printf("Nhap ma sach:");
    fgets(s->Masach, sizeof(s->Masach), stdin);
    s->Masach[strcspn(s->Masach, "\n")] ='\0';
    printf("Nhap ten sach: ");
    fgets(s->Tensach, sizeof(s->Tensach), stdin);
    s->Tensach[strcspn(s->Tensach, "\n")] ='\0';
    printf("Nhap ten tac gia:");
    fgets(s->Tacgia, sizeof (s->Tacgia), stdin);
    s->Tacgia[strcspn(s->Tacgia, "\n")] ='\0';
    printf("Nhap so luong: ");
    scanf("%d", &s->Soluong);
    while (getchar() != '\n');
}

void Nhapdanhsach(struct Sach ds[], int n){
    for(int i = 0; i<n; i++){
        printf("\n --- Nhap danh sach thu %d --- \n", i+1);
        Nhapsach(&ds[i]);
    }
}

void Xuatsach(struct Sach s){
printf("Ma: %s | Ten: %s | Tacgia: %s | Sl: %d\n", s.Masach, s.Tensach, s.Tacgia, s.Soluong);
}

void Xuatdanhsach(struct Sach ds[], int n){
    printf("\n --- Danh sach --- \n");
    for(int i=0; i<n; i++)Xuatsach(ds[i]);
}

void Timtheoten(struct Sach ds[], int n, char ten[]){
    int found = 0;
    for(int i=0; i<n; i++){
        if(strcmp(ds[i].Tensach, ten) == 0){
            printf("\n Thong tin sach tim thay: \n");
            Xuatsach(ds[i]);
            found = 1;
        }
    }
if(!found) printf("\n Khong tim thay! \n");
}

void Timtheotacgia(struct Sach ds[], int n, char tg[]){
    int found = 0;
    printf("\n Cac sach cua tac gia '%s': \n", tg);
    for(int i=0; i<n; i++){
        if(strcmp(ds[i].Tacgia, tg) == 0){
            Xuatsach(ds[i]);
            found = 1;
        }
    }
if(!found) printf("Khong tim thay tac gia nay! \n");
}

int Tongsosach(struct Sach ds[], int n){
    int tong= 0;
    for(int i=0; i<n; i++)tong += ds[i].Soluong;
    return tong;
}

int main()
{int n;
    printf("Nhap so luong sach: ");
    scanf("%d", &n);
    while (getchar() != '\n');

    struct Sach ds[100];
    Nhapdanhsach(ds, n);
    Xuatdanhsach(ds, n);

    char ten[50], tg[50];
    printf("\nNhap ten sach can tim: ");
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = '\0';
    Timtheoten(ds, n, ten);

    printf("\nNhap ten tac gia can tim: ");
    fgets(tg, sizeof(tg), stdin);
    tg[strcspn(tg, "\n")] = '\0';
    Timtheotacgia(ds, n, tg);

    printf("\nTong so sach trong thu vien: %d\n", Tongsosach(ds, n));

    return 0;
}
