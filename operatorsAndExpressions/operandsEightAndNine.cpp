    #include <iostream>
    #include <math.h>
    #include <cmath>
    using namespace std;

    /* Write an expression that checks from a given point {x, y} if it's in the 
    circle (K = {0,0} R = 5) and out of the rectangle [{-1,1}, {5, 5}] 
    Clarification: For the rectangle the lower left and the upper right corners are given */
        float x;
        float y;
        const int RADIUS = 5;

        bool isInCircle;
        bool isOutOfSquare; 

    int main(int argc, char const *argv[])
    {
        //double xYHypotenuse = sqrt(h);         
        //float xYHypotenuse = sqrt((int)(pow(x,2)) + (int)(pow(y,2))); 

        cout << "Hey! It's time to do some maths " << endl; 
        cout << "Please enter the x value of a coordinate" << endl;
        cin >> x;
        cout << "Please enter the y value of a coordinate" << endl;
        cin >> y;

        isInCircle = ((pow(x,2) + pow(y,2)) <= pow(RADIUS,2));
        isOutOfSquare = (((x<-1)&&(y<5))^((x<5&&x>-1)&&(y<1)));  

        cout << "Is your coordinate in the circle? "<< isInCircle << endl;
        cout << "Is your coordinate out of the square? "<< isOutOfSquare << endl;  
        return 0;
    }
 