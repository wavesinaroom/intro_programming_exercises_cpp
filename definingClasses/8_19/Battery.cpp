#include<iostream>
#include<optional>
#include<cstdarg>

enum class BatteryType {LiIon, NiMH, NiCd};

class Battery
{
private:
    /* data */
public:
    std::optional<const char *> battery_model;
    std::optional<const char *> battery_idle_time;
    std::optional<const char *> battery_hours_talk;

    BatteryType batteryType; 
    Battery(/* args */);
    Battery(const char* battery_model...);
    ~Battery();
};

Battery::Battery(/* args */)
{
}

Battery::Battery(const char* battery_model...)
{
    va_list args;
    va_start(args, battery_model);
    this->battery_model = va_arg(args, const char *);
    this->battery_idle_time = va_arg(args, const char *);
    this->battery_hours_talk = va_arg(args, const char *);
    va_end(args); 
}

Battery::~Battery()
{


}
