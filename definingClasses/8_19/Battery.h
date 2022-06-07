#pragma once

enum class BatteryType {LiIon, NiMH, NiCd};

class Battery
{
private:
    /* data */
public:

    BatteryType batteryType; 
    Battery(/* args */);
    Battery(BatteryType batteryType);
    ~Battery();
};

Battery::Battery(/* args */)
{
}

Battery::Battery(BatteryType batteryType)
{
    this->batteryType = batteryType; 
}

Battery::~Battery()
{
}
