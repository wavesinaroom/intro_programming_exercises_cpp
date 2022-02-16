    #include <iostream>

    using namespace std;

    // Write an expression that looks for a given integer 
    // if it's third digit is (right to left) is 7

    int main(int argc, char const *argv[])
    {
        int number = 253752;
        int divideByOneHundred = number / 100;
        bool isThirdDigitSeven = (divideByOneHundred % 10) == 7; 

        cout << divideByOneHundred << endl;
        cout << "Is the number third digit seven? " << isThirdDigitSeven << endl; 

        return 0;
    }
 