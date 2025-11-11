#include <stdio.h>

int main() {
    char str[1000];
    int u = 0, l = 0, d = 0, s = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            u++;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            l++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            d++;
        } else if (str[i] == ' ') {
            s++;
        }
    }

    printf("u = %d, l = %d, d = %d, s = %d\n", u, l, d, s);
    return 0;
}
