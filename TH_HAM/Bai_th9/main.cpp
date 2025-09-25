#include <iostream>
#include <cstring>

using namespace std;

void daoNguocChuoi(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int main() {
    char s[] = "I really like Code";

    cout << "Chuoi ban dau: " << s << endl;

    daoNguocChuoi(s);

    cout << "Chuoi sau khi dao nguoc: " << s << endl;

    return 0;
}
