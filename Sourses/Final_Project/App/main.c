#include "main.h"

int main (void)
{
    int check;
    printf("Choose program\n");
    scanf("%i",&check);

    switch(check)
    {
    case 1:
        first_task();
        break;

    case 2:
        timetable();
        break;

    case 3:
        matrix();
        break;

    case 4:
        strings();
        break;
    }
    system("pause");
    return 0;
}
