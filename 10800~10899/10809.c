#include <stdio.h>
#include <string.h>

int main() {
    int i, size, order[26];
    char S[101];
    scanf("%s", S);
    for(i=0; i<26; ++i)
        order[i] = -1;
    for(i=0, size=strlen(S); i<size; ++i) {
        if(order[S[i]-97] == -1)
            order[S[i]-97] = i;
    }
    for(i=0; i<26; ++i)
        printf("%d ", order[i]);
    return 0;
}