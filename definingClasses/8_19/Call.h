#include<iostream>
#include<vector>
#include<time.h>

class Call
{

private:
    time_t call_end = time(NULL);
    struct tm call_start;
    double call_duration;
    float call_price;
    friend class GSM; 
    friend class GSMCallHistoryTest;
public:

    static std::vector<Call> call_history; 
    Call(int hour...);
    ~Call();

    float CalculateBill(float call_price);
};


Call::Call(int hour...)
{
    va_list args;
    va_start(args, hour);

    this->call_start.tm_hour = hour;
    this->call_start.tm_min = va_arg(args, int); 
    this->call_start.tm_sec = va_arg(args, int);
    this->call_start.tm_year = va_arg(args, int);
    this->call_start.tm_mon = va_arg(args, int);
    this->call_start.tm_mday = va_arg(args, int);
    
    this->call_duration = difftime(this->call_end,mktime(&this->call_start));
    this->call_history.push_back(*this); 
}

Call::~Call()
{
}

std::vector<Call> Call::call_history;

