  #include<iostream>
  #include<optional>
  #include<cstdarg>
  #include "Battery.h"
  #include "Display.h"

  class GSM
  {
    static GSM nokiaN95; 

  private:
    /* data */
  public:
    std::optional<const char *> model;
    std::optional<const char *> manufacturer;
    std::optional<const char *> price;
    std::optional<const char *> owner;
    Battery battery;    
    Display display; 

    GSM(/* args */);
    GSM(const char * model...); 
    ~GSM();

    void printPhoneInfo();  
    static void printNokiaSpecs();

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

    va_end(args); 
  }

  GSM::~GSM()
  {
  
  }
  
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
    std::cout<<this->model.value()<<'\n';
    std::cout<<this->manufacturer.value()<<'\n';
    std::cout<<this->price.value()<<'\n';
    std::cout<<this->owner.value()<<'\n';
    //std::cout<<this->battery.batteryType<<'\n';
    std::cout<<this->battery.battery_model.value()<<'\n';
    std::cout<<this->battery.battery_idle_time.value()<<'\n';
    std::cout<<this->battery.battery_hours_talk.value()<<'\n';
    std::cout<<this->display.screen_buttons.value()<<'\n';
    std::cout<<this->display.screen_size.value()<<'\n';



  }

  GSM GSM::nokiaN95 = GSM("N95", "Nokia", "USD$333", "Luke Skywalker", "Li-lon 950", "280 hours", "5 hours","40x53 mm", "3 buttons"); 

  int main(int argc, char const *argv[])
  {
    GSM::printNokiaSpecs(); 

    return 0;
  }
  