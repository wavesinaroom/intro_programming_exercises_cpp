#include <iostream>
#include <string>

/*Write a code that by given name prints on the console "Hello, <name>!"
 (for example: "Hello, Peter!").*/

std::string name; 

void sayHello(std::string name)
{
    std::cout<<"Hi! My name is: "<<name<<std::endl; 
}

int main(int argc, char const *argv[])
{
    //Welcome message and input
    std::cout<<"Hey! What's your name?"<<std::endl;
    std::cin>>name; 

    sayHello(name); 

    std::cout<<"Nice to meet you "<<name<<", I'll be seeing you around then"<<std::endl; 

    return 0;
}
