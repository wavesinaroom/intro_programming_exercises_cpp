#include<iostream>
#include<chrono>
#include<vector>

class Call
{


private:
    //Needs to be adapted to a more real case use
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double>elapsed_seconds = end - start;
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

public:

    static std::vector<Call> CallHistory; 

    Call(/* args */);
    ~Call();
};

Call::Call(/* args */)
{
    CallHistory.push_back(*this);     
}

Call::~Call()
{
}

std::vector<Call> Call::CallHistory;