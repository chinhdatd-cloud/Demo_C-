#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int isStrongPassword(char *pw) {
    int length = strlen(pw);
    if (length < 8) return 0;

    bool hasUpper = false, hasLower = false, hasDigit = false;

    for (int i = 0; i < length; i++) {
        if (isupper(pw[i])) hasUpper = true;
        if (islower(pw[i])) hasLower = true;
        if (isdigit(pw[i])) hasDigit = true;
    }

    if (hasUpper && hasLower && hasDigit) return 1;
    return 0;
}

int main() {
    char pw[100];
    cout << "Nhap mat khau: ";
    cin >> pw;

    if (isStrongPassword(pw))
        cout << "Mat khau manh" << endl;
    else
        cout << "Mat khau khong manh" << endl;

    return 0;
}
