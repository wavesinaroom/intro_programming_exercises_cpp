#include<iostream>
#include<vector>
#include<time.h>

class Call
{
private:
    struct tm call_start={0};
    time_t call_end;
    double call_duration;
    float call_price;
public:
    friend class GSM; 

    static std::vector<Call> call_history; 
    Call(int hour ...);
    Call(/* args */);
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
    
    this->call_duration = difftime(call_end, mktime(&call_start));

    call_history.push_back(*this);     
}

Call::~Call()
{
}

std::vector<Call> Call::call_history;