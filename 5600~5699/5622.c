#include <stdio.h>

int getTimeFromAlphabet(char c) {
    static int order[26] = {
        2,2,2,
        3,3,3,
        4,4,4,
        5,5,5,
        6,6,6,
        7,7,7,7,
        8,8,8,
        9,9,9,9
    };
    return order[(int)(c-'A')]+1;
}

int main() {
    int i, time = 0;
    char word[16];
    scanf("%s", word);
    for(i=0; word[i]!=NULL; ++i) {
        time += getTimeFromAlphabet(word[i]);
    }
    printf("%d", time);
    return 0;
}