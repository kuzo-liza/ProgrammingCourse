#include "matrix.h"

void matrix(void)
{

    printf("Insert n\n");
    scanf("%i",&n);

    printf("Insert m\n");
    scanf("%i",&m);

    int **matrica=(int **)malloc(m*sizeof(int*));

    for(i = 0; i < m; i++)
        matrica[i] = (int*) malloc (n*sizeof(int));
    matrix_maker(matrica, n, m);
}
