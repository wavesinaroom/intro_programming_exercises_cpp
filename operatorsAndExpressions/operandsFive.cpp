    #include <iostream>

    using namespace std;

    // Write an expression that calculates the area of a trapezoid
    // by given sides a, b and height h

    int main(int argc, char const *argv[])
    {

        int sideA = 15;
        int sideB = 8;
        int height = 32;

        cout << "Trapezoid area: " << (height*(sideA+sideB)) / 2 << endl; 

        return 0;
    }
 