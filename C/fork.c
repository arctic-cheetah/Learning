#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct {
    int num;
} counter;

int main()
{
    counter *count = malloc(sizeof(counter));
    count->num = 0;
    /* fork a child process */
    fork();
    count->num+=1;
    /* fork another child process */
    fork();
    count->num+=1;

    /* and fork another */
    fork();
    count->num+=1;

    printf("Count is %d\n", count->num);
    return 0;
}
