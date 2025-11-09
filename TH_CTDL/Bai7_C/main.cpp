#include <iostream>
#include <string.h>

using namespace std;

struct Mathang{
    char mahang[20];
    char tenhang[50];
    int soluong;
    float dongia;
    int thoigianbaohanh;
};

void Nhapmathang(struct Mathang *mh){
    printf("Nhap ma hang: ");
    fgets(mh->mahang, sizeof(mh->mahang), stdin);
    mh->mahang[strcspn(mh->mahang, "\n")] = '\0';

    printf("Nhap ten hang: ");
    fgets(mh->tenhang, sizeof(mh->tenhang), stdin);
    mh->tenhang[strspn(mh->tenhang, "\n")]='\0';

    printf("Nhap so luong:");
    scanf("%d", &mh->soluong);
    printf("Nhap don gia:");
    scanf("%d", &mh->dongia);
    printf("Nhap thoi gian bao hanh:");
    scanf("%d", &mh->thoigianbaohanh);
    while (getchar() != '\n');
}

void Nhapdanhsach(struct Mathang ds[], int n){
    for (int i=0; i<n; i++){
        printf("\n--- nhap mat hang thu %d ---\n", i+1);
        Nhapmathang(&ds[i]);
    }

}

void Xuatmathang(struct Mathang mh){
    printf("Ma hang: %s | Ten hang: %s | SL: %d | Don gia: %.2f | Bh: %d thang\n", mh.mahang, mh.tenhang, mh.soluong, mh.dongia, mh.thoigianbaohanh);

}

void Xuatdanhsach(struct Mathang ds[], int n){
    printf("\n --- Danh sach mat hang --- \n");
    for (int i = 0; i < n; i++){
        Xuatmathang(ds[i]);
    }
}

void Timsoluonglonhat(struct Mathang ds[], int n){
    int max = ds[0].soluong;
    for (int i=0; i<n; i++)
        if (ds[i].soluong > max)
            max = ds[i].soluong;
            printf("\n Mat hang co so luong lon nhat: \n");
        for (int i = 0; i<n; i++)
            if(ds[i].soluong == max)
                Xuatmathang(ds[i]);
}

void Timdongiacaonhat(struct Mathang ds[], int n){
    float max = ds[0].dongia;
    for(int i=0; i<n; i++)
        if(ds[i].dongia > max)
        max = ds[i].dongia;
    printf("\n Mat hang co don gia cao nhat: \n");
    for(int i=0; i<n; i++)
        if(ds[i].dongia == max)
        Xuatmathang(ds[i]);
}

void Inbaohanhhon12(struct Mathang ds[], int n){
    printf("\n Mat hang co thoi gian bao hanh > 12 thang: \n");
    for(int i=0; i<n; i++)
        if(ds[i].thoigianbaohanh > 12)
        Xuatmathang(ds[i]);
}

void Sapxeptheosoluong(struct Mathang ds[], int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(ds[i].soluong > ds[j].soluong){
                struct Mathang tmp = ds[i];
                ds[i] = ds[j];
                ds[j] = tmp;
            }
        }
    }
}

int main()
{
   int n;
    printf("Nhap so luong mat hang: ");
    scanf("%d", &n);
    while (getchar() != '\n');

    struct Mathang ds[100];
    Nhapdanhsach(ds, n);

    Xuatdanhsach(ds, n);
    Timsoluonglonhat(ds, n);
    Timdongiacaonhat(ds, n);
    Inbaohanhhon12(ds, n);
    Sapxeptheosoluong(ds, n);

    printf("\nDanh sach sau khi sap xep tang dan theo so luong:\n");
    Xuatdanhsach(ds, n);
    return 0;
}
