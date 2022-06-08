  #include<iostream>
  #include<optional>
  #include<cstdarg>

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

    GSM(/* args */);
    GSM(const char * model...); 
    ~GSM();
  
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

  GSM GSM::nokiaN95 = GSM("N95", "Nokia", "USD$333", "Luke Skywalker", "Li-lon 950", "280 hours", "5 hours","40x53 mm", "3 buttons"); 

  int main(int argc, char const *argv[])
  {
    GSM::printNokiaSpecs(); 

    return 0;
  }
  