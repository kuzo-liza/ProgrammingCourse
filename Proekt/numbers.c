#include "first_task.h"

int numbers(int hour_beginning, int minutes_beginning, int seconds_beginning, int hour_end, int minutes_end, int seconds_end)
{
    beginning_number = hour_beginning * 3600 + minutes_beginning * 60 + seconds_beginning;
    end_number = hour_end * 3600 + minutes_end * 60 + seconds_end;

    final_number = end_number - beginning_number;
    return final_number;
}
