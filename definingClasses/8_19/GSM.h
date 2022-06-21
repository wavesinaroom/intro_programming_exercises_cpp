  #pragma once; 

  #include<iostream>
  #include<optional>
  #include<cstdarg>
  #include "Battery.h"
  #include "Display.h"
  #include "Call.h"

  class GSM
  {

  private:
    std::optional<const char *> model;
    std::optional<const char *> manufacturer;
    std::optional<const char *> price;
    std::optional<const char *> owner;
    Battery battery;    
    Display display; 
    Call call;
    friend class GSMTest; 
    friend class GSMCallHistoryTest;
  public:

    static GSM nokiaN95; 
    GSM(/* args */);
    GSM(const char * model...); 
    ~GSM();

    void printPhoneInfo();  
    static void printNokiaSpecs();
    void addPhoneCall();
    void removePhoneCall(int call_log);
    void removeAllCalls();
    static float calculateBill(int call_log, const float call_price = 0.37);
  };
  
  GSM::GSM(/* args */)
  {
  }
  
  GSM::GSM(const char * model...)
  {
    va_list args;
    va_start(args, model);
    
    this->model = model;
    this->manufacturer = va_arg(args,const char *);
    this->price = va_arg(args, const char *);
    this->owner = va_arg(args, const char *);
    this->battery.batteryType = va_arg(args, BatteryType);
    this->battery.battery_model = va_arg(args, const char *);
    this->battery.battery_idle_time = va_arg(args, const char *);
    this->battery.battery_hours_talk = va_arg(args, const char *);
    this->display.screen_buttons = va_arg(args, const char *);
    this->display.screen_size = va_arg(args, const char *);

    va_end(args ); 
  }

  GSM::~GSM()
  {
  
  }

  GSM GSM::nokiaN95 = GSM("N95", "Nokia", "USD$333", "Luke Skywalker", "Li-lon 950", "280 hours", "5 hours","40x53 mm", "3 buttons"); 
  
  void GSM::printNokiaSpecs()
  {
    std::cout<<"Nokia N95 specs"<<'\n';
    std::cout<<"Model: "<<nokiaN95.model.value()<<'\n';
    std::cout<<"Manufacturer: "<<nokiaN95.manufacturer.value()<<'\n';
    std::cout<<"Price: "<<nokiaN95.price.value()<<'\n';
    std::cout<<"Owner: "<<nokiaN95.owner.value()<<'\n';
  }

  void GSM::printPhoneInfo(){
    std::cout<<"Phones specs: "<<'\n';

    std::cout<<this->model.value_or("Model missing")<<'\n';
    std::cout<<this->manufacturer.value_or("Manufacter missing")<<'\n';
    std::cout<<this->price.value_or("Price missing")<<'\n';
    std::cout<<this->owner.value_or("Owner missing")<<'\n';
    
    switch (this->battery.batteryType.value())
    {
    case BatteryType::LiON:
        std::cout<<"Battery type: LiON"<<'\n';
        break;
    case BatteryType::NiCD:
        std::cout<<"Battery type: NiCD"<<'\n';
        break;         
    case BatteryType::NimH:
        std::cout<<"Battery type: NimH"<<'\n';
        break; 
    default:
        break;
    }
    
    std::cout<<this->battery.battery_model.value_or("Battery model missing")<<'\n';
    std::cout<<this->battery.battery_idle_time.value_or("Battery idle time missing")<<'\n';
    std::cout<<this->battery.battery_hours_talk.value_or("Battery hours talk missing")<<'\n';
    std::cout<<this->display.screen_buttons.value_or("Screen buttons missing")<<'\n';
    std::cout<<this->display.screen_size.value_or("Screen size mising")<<'\n';
    
  }

  void::GSM::addPhoneCall()
  {
    call = Call(); 
  }

  void::GSM::removePhoneCall(int call_log)
  {
    std::vector<Call>::iterator call_iterator = Call::call_history.begin()+call_log;
    Call::call_history.erase(call_iterator); 
  }

  void::GSM::removeAllCalls()
  {
    Call::call_history.clear();
  }

  float::GSM::calculateBill(int call_log, const float call_price = 0.37)
  {
    return call_price * Call::call_history[call_log].call_duration;
  }