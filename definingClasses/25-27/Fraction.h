/*25. Define a class Fraction, which contains information about the rational fraction 
   (e.g. ¼ or ½). Define a static method Parse() to create a fraction from a sting 
   (for example -3/4). Define the appropriate properties and constructors of the class.
   Also write property of type Decimal to return the decimal value of the fraction
   (e.g. 0.25).

   26. Write a class FractionTest, which tests the functionality of the class
   Fraction from previous task. Pay close attention on testing the function Parse
   with different input data.

   27. Write a function to cancel a fraction (e.g. if numerator and denominator are
   respectively 10 and 15, fraction to be cancelled to 2/3).*/

   #include<iostream>
   #include<cmath>

   class Fraction
   {
   private:
      int numerator, denominator;
      float decimal;
   public:
    friend class FractionTest; 
    
    Fraction();
    ~Fraction();
   
    static Fraction parseString(Fraction fraction, std::string input);
    void cancelFraction(int divisor);
   
   };
   
   Fraction::Fraction(){
      std::cout<<"New born child"<<'\n';
   }

   Fraction::~Fraction(){
      std::cout<<"RIP"<<'\n';
   }

   Fraction Fraction::parseString(Fraction fraction, std::string input){

      int fractionSign;
      int inputPos=0;

      if (input[0]=='-')
      {
         fractionSign = -1;
         input.erase(0,1);
      }else if(std::isdigit(input[0]))
      {
         fractionSign = 1;
      }else{
         std::cerr<<"Wrong input"<<'\n';
      }

      while(std::isdigit(input[inputPos]))
      {
         ++inputPos;
      }

      fraction.numerator = std::stoi(input.substr(0,inputPos));

      if (input[inputPos]=='/')
      {
         ++inputPos;
      }else{
         std::cerr<<"Wrong input"<<'\n';
      }
      
      fraction.denominator = std::stoi(input.substr(inputPos, input.length()-inputPos));
   
      fraction.decimal = static_cast<float>(fraction.numerator)/static_cast<float>(fraction.denominator)*static_cast<float>(fractionSign);   
    
      std::cout<<fraction.numerator<<'\n';
      std::cout<<fraction.denominator<<'\n';
      std::cout<<fraction.decimal<<'\n';
   }