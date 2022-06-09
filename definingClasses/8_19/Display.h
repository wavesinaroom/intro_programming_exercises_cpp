#pragma once

#include <iostream>
#include <optional>
#include <cstdarg>

class Display
{
private:
    std::optional<const char *> screen_size;
    std::optional<const char *> screen_buttons;
    friend class GSM;
public:

    Display(/* args */);
    Display(const char* screen_size...); 
    ~Display();
};

Display::Display(/* args */)
{
}

Display::Display(const char* screen_size...)
{
    va_list args;
    va_start(args, screen_size);
    this->screen_size = va_arg(args, const char *);
    this->screen_buttons = va_arg(args, const char *); 
    va_end(args); 
  
}

Display::~Display()
{
}
