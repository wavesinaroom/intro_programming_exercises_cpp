/*Define your own namespace CreatingAndUsingObjects and place in it 
two classes Cat and Sequence, which we used in the examples of the current chapter.
Define one more namespace and make a class, which calls the classes Cat and Sequence,
in it.*/

#include <iostream>

namespace creating_objects{
    std::string name;
    std::string colour; 

    class Cat{

        private: 
        
        public:
        //Members
        std::string name;
        std::string colour; 
        
        //Constructor no parameters
        Cat()
        {
            name="unnamed";
            colour="gray";
        } 
        //Constructor paramenters
        Cat(std::string n, std::string c)
        {
            name=n;
            colour=c; 
        }
        //Printing method 
        void say_miau()
        {
            std::cout<<"I am cat number: "<<this->name<<'\n'; 
        }
    };

    class Sequence{

        //Static field, holds current sequence value
        static int currentValue;

        //Denies class instantiation
        void sequence(){

        }

        //Taking next sequence value static method
        public: 
        static int next_value()
        {
            currentValue++;
            return currentValue;     }
    };
}

namespace created_objects
{
    class Caller
    {
    private:
    public:
        creating_objects::Cat cat;
        creating_objects::Sequence sequence; 
        Caller
        (creating_objects::Cat cat, creating_objects::Sequence sequence); 
        
    };
    
    Caller
    ::Caller
    (creating_objects::Cat cat, creating_objects::Sequence sequence)
    {
        cat=cat;
        sequence=sequence; 
    }

} 


