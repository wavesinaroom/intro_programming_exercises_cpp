/*Write a program, which prints on the standard output the count of
 days, hours, and minutes, which have passed since the computer is started
 until the moment of the program execution.*/

#include <iostream>
#include <chrono>
#include <sys/sysinfo.h>

int main(int argc, char const *argv[])
{

    struct sysinfo info;
    sysinfo(&info); 

    long uptime = info.uptime;

    std::cout<<uptime<<'\n'; 

    return 0;
}
