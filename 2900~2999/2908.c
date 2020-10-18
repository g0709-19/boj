#include <stdio.h>

int reverse(int number) {
    char string_number[4];
    char a;
    sprintf(string_number, "%d", number);
    a = string_number[2];
    string_number[2] = string_number[0];
    string_number[0] = a;
    string_number[0] -= '0';
    string_number[1] -= '0';
    string_number[2] -= '0';
    return string_number[0]*100+string_number[1]*10+string_number[2];
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    A = reverse(A);
    B = reverse(B);
    if(A > B)
        printf("%d", A);
    else
        printf("%d", B);
    return 0;
}