#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    time_t current_time = time(NULL);
    char today_date_string[20];
    char input_date_string[20];

    strftime(today_date_string, sizeof(today_date_string), "%Y%m%d", localtime(&current_time));
    fgets(input_date_string, sizeof(input_date_string), stdin);
	puts(today_date_string);
	puts(input_date_string);
    int int_today_date_string = atoi(today_date_string);
    int int_input_date_string = atoi(input_date_string);

    if (int_today_date_string < int_input_date_string)
    {
        puts("Date of mission start is in future!");
    }
    else
    {
        puts("This mission is already start or finished!");
    }
}
