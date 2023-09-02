#include <stdio.h>

int main() {
    int i = 1;

loop:
    if (i > 55)
        goto end;

    printf("%d\n", i);
    i+=2;
    goto loop;

end:
    return 0;
}
