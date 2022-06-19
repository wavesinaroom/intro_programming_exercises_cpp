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
    Call(/* args */);
    ~Call();

    float CalculateBill(float call_price);
};


Call::Call(/* args */)
{
    call_history.push_back(*this);     
}

Call::~Call()
{
}

std::vector<Call> Call::call_history;