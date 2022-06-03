 /*8. Define a class, which contains information about a mobile phone: model,
   manufacturer, price, owner, features of the battery (model, idle time and hours
   talk) and features of the screen (size and colors).

   9. Declare several constructors for each of the classes created by the previous 
   task, which have different lists of parameters (for complete information about a
   student or part of it). Data fields that are unknown have to be initialized 
   respectively with null or 0.

   10. To the class of mobile phone in the previous two tasks, add a static field
   nokiaN95, which stores information about mobile phone model Nokia N95. 
   Add a method to the same class, which displays information about this static field.

   11. Add an enumeration BatteryType, which contains the values for type of the
   battery (Li-Ion,NiMH, NiCd, …) and use it as a new field for the class Battery.

   12. Add a method to the class GSM, which returns information about the object as
   a string.

   13. Define properties to encapsulate the data in classes GSM, Battery and Display.

   14. Write a class GSMTest, which has to test the functionality of class GSM.
   Create few objects of the class and store them into an array.
   Display information about the created objects. Display information about the
   static field nokiaN95.

   15. Create a class Call, which contains information about a call made via
   mobile phone. It should contain information about date, time of start and duration
   of the call.

   16. Add a property for keeping a call history – CallHistory, which holds a list
   of call records.

   17. In GSM class add methods for adding and deleting calls (Call) in the archive 
   of mobile phone calls. Add method, which deletes all calls from the archive.

   18. In GSM class, add a method that calculates the total amount of calls (Call)
   from the archive of phone calls (CallHistory), as the price of a phone call is 
   passed as a parameter to the method.

   19.   Create a class GSMCallHistoryTest, with which to test the functionality of the class GSM,
   from task 12, as an object of type GSM. Then add to it a few phone calls (Call). Display
   information about each phone call. Assuming that the price per minute is 0.37, calculate and
   display the total cost of all calls. Remove the longest conversation from archive with phone
   calls and calculate the total price for all calls again. Finally, clear the archive.
   */

  #include<iostream>
  #include<optional>
  #include<cstdarg>
  #include<string>

  class MobilePhone
  {
  private:
    /* data */
  public:
    std::optional<const char *> model;
    std::optional<const char *> manufacturer;
    std::optional<const char *> price;
    std::optional<const char *> owner;
    std::optional<const char *> battery_model;
    std::optional<const char *> battery_idle_time;
    std::optional<const char *> battery_hours_talk;
    std::optional<const char *> screen_size;
    std::optional<const char *> screen_buttons;


    MobilePhone(/* args */);
    MobilePhone(const char * model...); 
    ~MobilePhone();
  };
  
  MobilePhone::MobilePhone(/* args */)
  {
  }
  
  MobilePhone::MobilePhone(const char * model...)
  {
    va_list args;
    va_start(args, model);
    this->model = model;
    this->manufacturer = va_arg(args,const char *);
    this->price = va_arg(args, const char *);
    this->owner = va_arg(args, const char *);
    this->battery_model = va_arg(args, const char *);
    this->battery_idle_time = va_arg(args, const char *);
    this->battery_hours_talk = va_arg(args, const char *);
    this->screen_size = va_arg(args, const char *);
    this->screen_buttons = va_arg(args, const char *); 
    va_end(args); 
  }

  MobilePhone::~MobilePhone()
  {
  
  }
  
  int main(int argc, char const *argv[])
  {
    MobilePhone mobilePhone = MobilePhone("S5", "Nokia", "400EUR");
    return 0;
  }
  