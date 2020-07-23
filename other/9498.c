#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    a /= 10;
    if (a >= 9)
        printf("A");
    else if (a == 8)
        printf("B");
    else if (a == 7)
        printf("C");
    else if (a == 6)
        printf("D");
    else
        printf("F");
    return 0;
}