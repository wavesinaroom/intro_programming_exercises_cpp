/*Write a program that checks whether the parentheses are placed correctly in an
arithmetic expression. Example of expression with correctly placed brackets: ((a+b)/5-d).
Example of an incorrect expression: ((a+b))).*/

#include <iostream>

void check_parentheses (std::string arithmetic_expression)
{
    char open_bracket = '(';
    char close_bracket = ')';
    bool is_first_bracket = true; 
    int bracket_count=0;

    for (size_t i = 0; i < arithmetic_expression.length(); i++)
    {
        if(arithmetic_expression[i]==')')
        {
            //if first bracket equals ) the expression is wrong 
            if(i==0&&is_first_bracket)
            {
                throw 0; 
            }else
            {
                is_first_bracket = false; 
                bracket_count--; 
            }
        }else if(arithmetic_expression[i]=='(')
        {
            bracket_count++; 
        }
    }

    if (bracket_count==0)
    {
        std::cout<<"You've got well placed brackets"<<'\n';
    }else
    {
        //if ( braket count does not equal ) braket count the expression is wrong
        throw 1;
    }
} 

int main(int argc, char const *argv[])
{
    std::cout<<"Hey! Write an arithmetic expression with parentheses"<<'\n';
    std::cout<<"I'll check if they're placed well in it"<<'\n'; 
    
    std::string user_expression; 
    std::cin>>user_expression; 

    try
    {
        check_parentheses(user_expression); 
    }
    catch(int wrong_bracket)
    {
        std::cerr << "Your expression starts with a closing bracket" << '\n';
    }
    catch(int missing_bracket)
    {
        std::cerr << "A bracket is missing in your expression"<< '\n';
    }

    return 0;
}

