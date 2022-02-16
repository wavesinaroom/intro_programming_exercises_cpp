    #include <iostream>

    using namespace std;

    /* The gravitional field of the Moon is is aproximately %17 of that on the Earth.
    Write a program that calculates the weight on he Moon by a given weight on the Earth*/

    int main(int argc, char const *argv[])
    {

        float weightOnEarth;
        const float MOON_GRAVITY_EARTH_RATIO = 0.17;
         

        cout << "Welcome to the Moon! Do you want to know weight here?" << endl;
        cout << "Please enter your weight" << endl;
        cin >> weightOnEarth;
        cout << "Your weight on the moon is: " << weightOnEarth - (weightOnEarth * MOON_GRAVITY_EARTH_RATIO) << endl; 

        return 0;
    }
 