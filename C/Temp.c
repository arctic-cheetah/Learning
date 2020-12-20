#include <stdio.h>

int main(int argc, char** argv) {
    unsigned long long value = -1;
    printf("%llu\n", value);
    int counter = 0;
    while(value) {
        ++counter;
        value &= value-1;
    }
    printf("%d\n",counter);
    return 0;
}
