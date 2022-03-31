/* Write a program that reads the date and time entered in the format
"day.month.year hour:minutes:seconds" and prints the date and time after 6 hours
and 30 minutes in the same format.*/

#include <iostream>
#include <vector>

//CODE DOESN'T COMPILE, STILL DON'T KNOW HOW TO RETURN A POINTER OF A VECTOR

void Print_Vector_Contents(std::vector<int> vector)
{
    std::cout << vector[0] << '.' << vector[1] << '.' << vector[2] << ' ' << vector[3] << ':' << vector[4] << ':' << vector[5] << '\n';
}
std::vector<int> String_To_Int(std::string input_date)
{
    std::vector<int> date_digits;
    int day_year_swapper = 0;

    if (input_date[2] != '.' || input_date[5] != '.' || input_date[10] != ' ' || input_date[13] != ':' || input_date[16] != ':')
    {
        std::cerr << "Wrong input format, try again" << '\n';
    }
    else
    {

        int number_start = 0;
        int number_end = 0;

        for (size_t i = 0; i <= input_date.size(); i++)
        {
            if (!isdigit(input_date[i]) || i == input_date.size())
            {
                number_end = i;
                date_digits.push_back(stoi(input_date.substr(number_start, (number_end - number_start))));
                number_start = number_end + 1;
            }
        }

        day_year_swapper = date_digits[2];
        date_digits[2] = date_digits[0];
        date_digits[0] = day_year_swapper;
    }
    return date_digits;
}

bool Is_Leap_Year(std::vector<int> input_date_digits)
{
    const int YEAR_DIGIT = 0;
    bool is_leap_year = false;
    if (input_date_digits[YEAR_DIGIT] % 4 == 0)
    {
        is_leap_year = true;
    }
    if (input_date_digits[YEAR_DIGIT] % 100 == 0)
    {
        is_leap_year = false;
    }
    if (input_date_digits[YEAR_DIGIT] % 400 == 0)
    {
        is_leap_year = true;
    }
    return is_leap_year;
}

void Add_To_Date(std::vector<int>& input_date, bool is_leap_year, int units, int amount)
{
    int base = 0;
    const int FEBRUARY = 2;
    int remainder = 0;

    switch (units)
    {
    // Year
    case 0:
        Print_Vector_Contents(input_date);
        return;
    // Months
    case 1:
        base = 12;
        break;
    // Days
    case 2:
        if (is_leap_year && input_date[1] == FEBRUARY)
        {
            base = 29;
        }
        else if (!is_leap_year && input_date[1] != FEBRUARY)
        {
            base = 28;
        }
        else if (input_date[1] % 2 == 1) // odd months
        {
            base = 31;
        }
        else if (input_date[1] % 2 == 0) // even months
        {
            base = 30;
        }
        break;
    // Hours
    case 3:
        base = 24;
        break;
    // Minutes
    case 4:
        base = 60;
        break;
    // Seconds
    case 5:
        base = 60;
        break;
    default:
        std::cerr << "Field does not exist" << '\n';
        break;
    }

    if ((input_date[units] + amount) < base)
    {
        input_date[units] += amount;
        Print_Vector_Contents(input_date);
    }
    else
    {
        remainder = (input_date[units] + amount) - base;
        Add_To_Date(input_date, is_leap_year, units-1, 1);
    }
}

int main(int argc, char const *argv[])
{
    std::string input_date = "05.04.2301 04:10:33";

    Add_To_Date(String_To_Int(input_date), Is_Leap_Year(String_To_Int(input_date)), 4, 30);
    Add_To_Date(String_To_Int(input_date), Is_Leap_Year(String_To_Int(input_date)), 3, 6);

    return 0;
}
