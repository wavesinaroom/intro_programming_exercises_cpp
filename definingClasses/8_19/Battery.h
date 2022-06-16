#pragma once

#include<iostream>
#include<optional>
#include<cstdarg>

enum class BatteryType {LiON, NimH, NiCD};

class Battery
{
private:

    std::optional<const char *> battery_model;
    std::optional<const char *> battery_idle_time;
    std::optional<const char *> battery_hours_talk;
    std::optional<BatteryType> batteryType; 
    friend class GSM; 
    friend class GSMTest;
public:

    Battery(/* args */);
    Battery(BatteryType batteryType...);
    ~Battery();
};

Battery::Battery(/* args */)
{
}

Battery::Battery(BatteryType batteryType...)
{
    va_list args;
    va_start(args, batteryType);
    this->batteryType = batteryType;
    this->battery_model = va_arg(args, const char *);
    this->battery_idle_time = va_arg(args, const char *);
    this->battery_hours_talk = va_arg(args, const char *);
    va_end(args); 
}

Battery::~Battery()
{


}
