    #include <iostream>

    using namespace std;

    // Write a program that prints on the console the perimeter
    // and the area of a rectangle by given side and height entered by the user

    int main(int argc, char const *argv[])
    {

        int side;
        int height;

        cout << "Hey there! We're going to calculate the area of a rectangle" << endl;
        cout << "Please enter side value " << endl;
        cin >> side;
        cout << "Please enter height value " << endl;
        cin >> height; 
        cout << "Rectangle area: " << side * height << endl; 

        return 0;
    }
 