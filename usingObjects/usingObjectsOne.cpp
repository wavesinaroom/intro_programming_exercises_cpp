/*Write a program, which reads from the console a year 
and checks if it is a leap year.*/

#include <iostream>


//C++ LACKS OF LEAP YEAR FUNCTION SUGGESTED IN THE BOOK 
//TAKEN FROM https://en.wikipedia.org/wiki/Leap_year
/*These extra days occur in each year which is an integer multiple of 4
 (except for years evenly divisible by 100, but not by 400). 
 The leap year of 366 days has 52 weeks and two days,
  hence the year following a leap year will start later by two days of the week.*/

  int year;

  //must be divisible by 4
  //result must not be even when dividing by 100 
  //result must be odd when dividing by 400 


int main(int argc, char const *argv[])
{
    std::cout<<"Hey! Let's check if you've got a leap year"<<'\n';
    std::cout<<"PLease enter any year you want to check"<<'\n';

    std::cin>>year;

    if(year%4==0)
    {
        if(year%100!=0||year%400!=0)
            std::cout<<year<<" is a leap year"<<'\n';
    }


    return 0;
}
