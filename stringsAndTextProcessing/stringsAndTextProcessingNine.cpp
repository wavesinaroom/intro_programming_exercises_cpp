/*Write a program that encrypts a text by applying XOR (excluding or) operation
between the given source characters and given cipher code. The encryption should be
done by applying XOR between the first letter of the text and the first letter of the
code, the second letter of the text and the second letter of the code, etc. until the
last letter of the code, then goes back to the first letter of the code and the next 
letter of the text. Print the result as a series of Unicode escape characters \xxxx.

Sample source text: "Test". Sample cipher code: "ab". The result should be 
the following: "\u0035\u0007\u0012\u0016".*/

//NOT GONNA CONVERT TO UNICODE
//SOLUTION TAKEN FROM: https://www.codespeedy.com/c-program-to-encrypt-and-decrypt-a-string/ 

#include <iostream>
#include<string.h>

int main(int argc, char const *argv[])
{
    char input_text[100];
    char temp_text;
    int i, cyphing_key;

    std::cout<<"Please enter your message: "<<'\n';
    std::cin>>input_text;
    std::cout<<"Please enter your cyphing key"<<'\n';
    std::cin>>cyphing_key;

    for (size_t i = 0; input_text[i] != '\0'; i++)
    {
        temp_text = input_text[i];
        if(temp_text >= 'a' && temp_text <= 'z')
        {
            temp_text += cyphing_key; 

            if (temp_text>'z')
            {
                temp_text = temp_text - 'z' + 'a' - 1; 
            }
            
            input_text[i] = temp_text; 
        }else if(temp_text>='A'&&temp_text<='Z')
        {
            temp_text+=cyphing_key;

            if (temp_text>'Z')
            {
                temp_text = temp_text - 'Z' + 'A' - 1;
            }
            input_text[i] = temp_text; 
        }            
    }
    
    std::cout<<"Your encrypted message: "<< input_text << '\n'; 

    return 0;
}




