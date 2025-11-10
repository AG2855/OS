#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *en[])
{
    int i, j, c, arr[argc], ele;

    // Convert arguments to integers
    for (j = 0; j < argc - 1; j++)
    {
        arr[j] = atoi(argv[j]);
    }

    ele = atoi(argv[j]);
    i = 0;
    j = argc - 2;
    c = (i + j) / 2;

    while (arr[c] != ele && i <= j)
    {
        if (ele > arr[c])
            i = c + 1;
        else
            j = c - 1;
        c = (i + j) / 2;
    }

    if (i <= j)
        printf("\nElement found in given array");
    else
        printf("\nElement not found in given array");

    return 0;
}
