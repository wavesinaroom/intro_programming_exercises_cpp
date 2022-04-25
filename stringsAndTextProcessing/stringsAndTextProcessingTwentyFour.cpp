/* Write a program that reads a string from the console and replaces every sequence of
   identical letters in it with a single letter (the repeating letter). Example:
   "aaaaabbbbbcdddeeeedssaa" à "abcdedsa". */

   #include <iostream>

   void replaceRepeatedLetter(std::string &inputString)
   {

       char ch = inputString[0]; 
        std::string::size_type length = 0; 

        for (size_t start = 0; start < inputString.size(); ++start)
        {
            if (inputString.at(start)==inputString.at(start+1))
            {
                ch = inputString.at(start); 
                while (inputString[start+length]==ch)
                {
                    ++length; 
                }

                inputString.erase(start, length-1); 
                length = 0; 
            }
        }
        std::cout<<inputString<<'\n'; 
        
   }

   int main(int argc, char const *argv[])
   {
       std::string inputString = "aaaaabbbbbcdddeeeedssaa"; 
        replaceRepeatedLetter(inputString); 
       return 0;
   }
   