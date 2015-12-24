#include "first_task.h"

void a_gap_of_time()
{
    printf("Insert time of the beginning\n");
    scanf("%d%d%d", &hour_beginning, &minutes_beginning, &seconds_beginning);

    printf("Insert time of the end\n");
    scanf("%d%d%d", &hour_end, &minutes_end, &seconds_end);

    printf("%d", numbers(hour_beginning, minutes_beginning, seconds_beginning, hour_end, minutes_end, seconds_end));
}
