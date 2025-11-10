#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int val[10], ele;
    pid_t pid;
    char *cval[10];
    int i, j, n, temp;

    printf("\nEnter the size of array: ");
    scanf("%d", &n);

    printf("\nEnter the numbers:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("\nElements entered are:\n");
    for (i = 0; i < n; i++)
        printf("%d ", val[i]);

    // Bubble sort
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (val[j] > val[j + 1])
            {
                temp = val[j];
                val[j] = val[j + 1];
                val[j + 1] = temp;
            }
        }
    }

    printf("\nSorted elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d ", val[i]);

    printf("\nEnter element to search: ");
    scanf("%d", &ele);

    val[i] = ele; // append element at the end

    // Convert int array to string array for execv()
    for (i = 0; i < n + 1; i++)
    {
        char a[10];
        snprintf(a, sizeof(a), "%d", val[i]);
        cval[i] = malloc(strlen(a) + 1);
        strcpy(cval[i], a);
    }
    cval[i] = NULL;

    pid = fork();
    if (pid == 0)
    {
        execv(argv[1], cval);
        perror("\nError in execv call");
    }

    return 0;
}
