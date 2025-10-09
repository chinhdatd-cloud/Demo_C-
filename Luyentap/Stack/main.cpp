#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100   // Kích thước tối đa của Stack

// 1. Định nghĩa cấu trúc Stack (chứa ký tự)
typedef struct {
    char data[MAX_SIZE];
    int top;
} CharStack;

// Khởi tạo Stack rỗng
void initializeStack(CharStack *s) {
    s->top = -1;
}

// Kiểm tra Stack rỗng
int isStackEmpty(CharStack *s) {
    return s->top == -1;
}

// Kiểm tra Stack đầy
int isStackFull(CharStack *s) {
    return s->top == MAX_SIZE - 1;
}

// Thêm phần tử vào Stack (Push)
void push(CharStack *s, char value) {
    if (isStackFull(s)) {
        printf("Lỗi: Stack Overflow!\n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

// Lấy phần tử ra khỏi Stack (Pop)
char pop(CharStack *s) {
    if (isStackEmpty(s)) {
        printf("Lỗi: Stack Underflow!\n");
        return '\0';  // Trả về ký tự rỗng nếu stack rỗng
    }
    char value = s->data[s->top];
    s->top--;
    return value;
}

// 2. Hàm chính để đảo ngược chuỗi
void reverseString(char *str) {
    int len = strlen(str);
    CharStack s;
    initializeStack(&s);

    // Đưa từng ký tự vào Stack (LIFO)
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    // Lấy các ký tự ra khỏi Stack (đảo ngược thứ tự)
    for (int i = 0; i < len; i++) {
        str[i] = pop(&s);
    }
}

// 3. Hàm main
int main() {
    char myString[] = "LAP TRINH C";

    printf("Chuoi goc: %s\n", myString);

    reverseString(myString);

    printf("Chuoi sau khi dao nguoc: %s\n", myString);

    return 0;
}
