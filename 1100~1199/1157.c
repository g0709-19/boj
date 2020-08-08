#include <stdio.h>
#include <string.h>
 
char toUpperCase(char c) {
    if(c >= 'a' && c <= 'z')
        return c+('A'-'a');
    else
        return c;
}
 
int main() {
    int i, size, max_value, max_order, over = 0;
    int count[26] = {0,};
    char word[1000001];
    scanf("%s", word);
    for(i=0, size=strlen(word); i<size; ++i) {
        ++count[toUpperCase(word[i])-'A'];
    }
    for(i=0; i<26; ++i) {
        if(i == 0) {
            max_value = count[i];
            max_order = i;
        }
        if(count[i] > max_value) {
            max_value = count[i];
            max_order = i;
        }
    }
    for(i=0; i<26; ++i) {
    	if(count[i] == max_value && max_order != i) {
    		over = 1;
    		break;
    	}
    }
    if (over) {
    	printf("?");
    } else {
    	printf("%c", max_order+'A');
    }
    return 0;
}