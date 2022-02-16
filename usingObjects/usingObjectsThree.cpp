/*Write a program, which prints, on the console which day of the week is today.*/

// SOLUTION TAKEN FROM: https://www.cplusplus.com/reference/ctime/mktime/

#include <iostream>
#include <time.h>

int main(int argc, char const *argv[])
{
    // Current time/date based on current system
    time_t rawtime = time(0);
    struct tm *currentTime;
    const char *weekday[] = {"Sunday", "Monday",
                             "Tuesday", "Wednesday",
                             "Thursday", "Friday", "Saturday"};

    // Assign values to the structure
    currentTime = localtime(&rawtime);

    std::cout << "Today is..." << weekday[currentTime->tm_wday] << '\n';

    return 0;
}
