#include <stdio.h>
#include <time.h>

void main()
{
    time_t current_time;
    time(&current_time);
    char* tp = ctime(&current_time);

    printf("My name and sid is: Liu Shiyi (201180078)\n");
    printf("Current time: %s", tp);
}