    #include <iostream>

    using namespace std;

    // Write an expression that checks whether the third bit in a given integer
    // is 1 or 0
    int main(int argc, char const *argv[])
    {
        // Book solution

        int number = 7;
        bool isThirdBitOne = (number & 8) !=  0;


        cout << "Is the number third bit 1 or 0? " << isThirdBitOne << endl; 

        return 0;
    }
 