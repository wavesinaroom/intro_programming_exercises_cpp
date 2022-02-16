    #include <iostream>

    using namespace std;

    // Write a boolean expression that checks whether a given integer is 
    // divisible by 5 and 7 without a remainder

    int main(int argc, char const *argv[])
    {
        int number = 40;
        
        cout << "Is number div by 5 or 7? : " << (number%5)<<" "<<(number%7)<< endl;  


        return 0;
    }
    