#include <iostream>
#include <math.h>
using namespace std;

/* Write a program that gets the coefficients a, b, c of a quadratic 
equation: ax²+bx+c, calculates and prints its real roots (if they exist)
Quadratic equations may have 0, 1 or 2 real roots*/

int main(int argc, char const *argv[])
{
    int a, b, c; 
    double discriminant; 

    cout<<"Let's find out the roots of a quadratic equation "<<endl;
    cout<<"Enter a value for a:";
    cin>>a;
    cout<<"Enter a value for b:";
    cin>>b;
    cout<<"Enter a value for c:"; 
    cin>>c;

    discriminant = (pow(b,2)-(4*a*c));  
    if (discriminant==0)
    {
        cout<<"The equation has a one double real root "<<(-b/(2*a))<<endl;
    }else if (discriminant>0)
    {
        cout<<"The equations has "<<(-b+sqrt(discriminant))/2*a<<" and "<<
        (-b-sqrt(discriminant))/2*a<<" as roots "<<endl; 
    }else if (discriminant<0){
        cout<<"The quadratic equation has no real roots "<<endl; 
    }
    return 0;
}

    /*Alternative version from 
    https://www.programiz.com/cpp-programming/examples/quadratic-roots*/

    /*
    #include <iostream>
    #include <cmath>
    using namespace std;

    int main() {

    float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;
    discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "Roots are real and different." << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    
    else if (discriminant == 0) {
        cout << "Roots are real and same." << endl;
        x1 = -b/(2*a);
        cout << "x1 = x2 =" << x1 << endl;
    }

    else {
        realPart = -b/(2*a);
        imaginaryPart =sqrt(-discriminant)/(2*a);
        cout << "Roots are complex and different."  << endl;
        cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
    }

    return 0;
}
    */
    


