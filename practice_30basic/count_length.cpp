// Count the Length of a String
#include<stdio.h>

int main(){
    char s[1000];
    printf("Enter a string: ");
    scanf("%s", s);

    int l = 0;
    for(int i = 0; s[i] != '\0'; i++){
        l++;
    }
    printf("Length of the string = %d\n",l);
    return 0;
}