#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

int Demkhoangtrang(char s[]){
    int dem = 0;
    for (int i = 0;s[i] != '\0'; i++){
        if (s[i] == '')dem++;
    }
return dem;
}

void Xoakhoangtrangthua(char s[]){
    int i=0, j=0;
    while (s[i] == '') i++;
    for (; s[i] != '\0'; i++){
        if (!(s[i] == '' && s[i+1] == '')){
            s[j++] = s[i];
        }
    }
    if (j>0 && s[j-1] == '') j--;
    s[j] = '\0';

}

void Viethoatudau(char s[]){
    int len = strlen(s);
    int cap = 1;
    for (int i=0; i<len; i++){
        if (isspace(s[i])){
            cap = 1;
        } else if (cap && isalpha(s[i])){
           s[i] = toupper(s[i]);
           cap = 0;
        }else {
            s[i] = tolower(s[i]);
        }
    }
}

void Daonguocchuoi(char s[]){
    int len = strlen(s);
    for (int i=0; i<len\2; i++){
        cham tmp = s[i];
        s[i] = s[len - 1 -i];
        s[len - 1 - i] = tmp;
    }

}
int main()
{
   char s[200];
    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    printf("So khoang trang: %d\n", Demkhoangtrang(s));

    Xoakhoangtrangthua(s);
    printf("Sau khi xoa khoang trang thua: \"%s\"\n", s);

    Viethoatudau(s);
    printf("Sau khi viet hoa dau moi tu: \"%s\"\n", s);

    Daonguocchuoi(s);
    printf("Chuoi sau khi dao nguoc: \"%s\"\n", s);

    return 0;
}
