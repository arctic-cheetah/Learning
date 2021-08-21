#include <unistd.h>
#include <stdio.h>

int main()
{
    int i;
    for (i = 0; i < 4; i++)
        fork();
    
    printf("Me!\n");
    return 0;
}