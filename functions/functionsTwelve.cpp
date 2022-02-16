/*Write a method that calculates the sum of two polynomials with integer coefficients,
 for example (3x2 + x - 3) + (x - 1) = (3x2 + 2x - 4).*/

#include <iostream>
#include <array>

#define POLY_MAX_DEGREE 100

// Struct that has coefficitients and exponents separately
struct Polynomial
{
    int exponents[POLY_MAX_DEGREE];
    double coefficients[POLY_MAX_DEGREE];
};

typedef struct Polynomial polynomial;

// EXTRACT METHOD TAKEN FROM http://www.cplusplus.com/forum/general/118352/
Polynomial extractCoefficientExponent(std::string polynomialString)
{
    // Exits program if string is empty
    if (polynomialString == "")
    {
        std::cerr << "There's no polynomial";
        std::exit;
    }
    int polyStrSize = polynomialString.size();

    //Counts monomials (each NumberX^Exponent) in the polynomial+
    int monomialsCount = 1;
    for (int polyStrPos = 1; polyStrPos < polynomialString.size(); polyStrPos++)
    {
        if (polynomialString[polyStrPos] == '+' || polynomialString[polyStrPos] == '-')
        {
            monomialsCount++;
        }
    }

    // Adds + signs to the beginning of the string for parsing
    // Whether its first position is a digit or x
    if (isdigit(polynomialString[0]))
        polynomialString.insert(0, "+");
    if (polynomialString[0] == 'x')
        polynomialString.insert(0, "+");

    // Puts a + sign at the end of the string
    polynomialString.append("+");

    // Updates the size of the polynomial string
    polyStrSize = polynomialString.size();

    //Extracting the monomials as monomStr
    int monoStrPos=0;
    int monoStrSubStrStart=0;
    std::string monomStr[POLY_MAX_DEGREE];

    // Checks if there's a + or - sign in each position of the polynomial
    // Extracts a substring from the breaking point
    for (int polyStrPos = 1; polyStrPos < polynomialString.size(); polyStrPos++)
    {
        if (polynomialString[polyStrPos] == '+' || polynomialString[polyStrPos] == '-')
        {
            monomStr[monoStrPos++] = polynomialString.substr(monoStrSubStrStart, polyStrPos - monoStrSubStrStart);
            monoStrSubStrStart = polyStrPos;
        }
    }

    // Formats monomials to have the same form
    for (int monomsIndex = 0; monomsIndex < monomialsCount; monomsIndex++)
    {
        if (monomStr[monomsIndex][1] == 'x')
            monomStr[monomsIndex].insert(1, "1");

        bool flag = false; // Tells if there's x in the position
        int monomLength = monomStr[monomsIndex].size();
        for (int monomCharPos = 1; monomCharPos < monomLength; monomCharPos++)
            if (monomStr[monomsIndex][monomCharPos] == 'x')
            {
                flag = true;
                if (monomCharPos == monomLength - 1)
                {
                    monomStr[monomsIndex].append("^1");
                    break;
                }
            }
        if (!flag)
            monomStr[monomsIndex].append("x^0");
    }

    // Extract coefficients and exponents
    Polynomial polynomial;
    polynomial.exponents[POLY_MAX_DEGREE] = {0};
    polynomial.coefficients[POLY_MAX_DEGREE] = {0};
    for (int monomsIndex = 0; monomsIndex < monomialsCount; monomsIndex++)
    {
        int monomSize = monomStr[monomsIndex].size();
        for (int monomCharPos = 0; monomCharPos < monomSize; monomCharPos++)
        {
            if (monomStr[monomsIndex][monomCharPos] == '^')
            {
                polynomial.exponents[monomsIndex] = std::stoi(monomStr[monomsIndex].substr(monomCharPos + 1, monomSize - monomCharPos));
                polynomial.coefficients[monomsIndex] = std::stod(monomStr[monomsIndex].substr(0, monomCharPos));
                break;
            }
        }
    }

    // Looks for the max of exponents
    int maxExponent = 0;
    for (auto &&exponent : polynomial.exponents)
    {
        if (exponent >= maxExponent)
            maxExponent = exponent;
    }

    // Generating monomial with degree = maxExponent
    std::string newMonomial[POLY_MAX_DEGREE];
    for (int newMonIndex = maxExponent; newMonIndex >= 0; newMonIndex--)
    {
        newMonomial[newMonIndex] = "+0x^" + std::to_string(newMonIndex);
    }

    // Mixing given and null
    for (int mixingIndex = monomialsCount; mixingIndex >= 0; mixingIndex--)
    {
        newMonomial[polynomial.exponents[monomialsCount]] = monomStr[mixingIndex];
    }

    // Creating the complete form of the polynomial
    std::string finalPolyStr;
    for (int finalPolyIndex = maxExponent; finalPolyIndex >= 0; finalPolyIndex--)
    {
        finalPolyStr += newMonomial[finalPolyIndex];
    }

    // Extracts coefficients and exponents from final form
    int finalPolyStrSize = finalPolyStr.size();
    int start[POLY_MAX_DEGREE] = {0};
    int stop[POLY_MAX_DEGREE] = {0};
    int startStopIndexes = 0;
    for (int finalStrSubIndex = 0; finalStrSubIndex < finalPolyStrSize; finalStrSubIndex++)
    {
        if (finalPolyStr.substr(finalStrSubIndex, 1) == "+" || finalPolyStr.substr(finalStrSubIndex, 1) == "-")
            start[startStopIndexes] = finalStrSubIndex;
        if (finalPolyStr.substr(finalStrSubIndex, 1) == "x")
            stop[startStopIndexes++] = finalStrSubIndex;
    }

    for (int coeffExponIndex = 0; coeffExponIndex < startStopIndexes; coeffExponIndex++)
    {
        polynomial.exponents[coeffExponIndex] = maxExponent - coeffExponIndex;
        polynomial.coefficients[coeffExponIndex] = stod(finalPolyStr.substr(start[coeffExponIndex], stop[startStopIndexes] - start[startStopIndexes]));
    }

    return polynomial;
}

//Sums Polynomials
void sumPolynomials(polynomial firstPoly, polynomial secondPoly)
{
    polynomial resultPoly;
    int sumIndex; 
    
    while (sumIndex<sizeof(firstPoly.coefficients)&&sumIndex<sizeof(secondPoly.coefficients))
    {
        resultPoly.coefficients[sumIndex]=(firstPoly.coefficients[sumIndex]+secondPoly.coefficients[sumIndex]); 
        sumIndex++;  
    }
    
    for (auto &&coefficient : resultPoly.coefficients)
    {
        std::cout<<coefficient<<" ";
    }
    std::cout<<'\n'; 
}

void printPolynomial(Polynomial polynomial)
{
    for (auto &&coefficient : polynomial.coefficients)
    {
        std::cout<<"**"<<coefficient<<'\n';
    }
    
    for (auto &&exponent : polynomial.exponents)
    {
        std::cout<<"**"<<exponent<<'\n';
    }
}

int main(int argc, char const *argv[])
{
    sumPolynomials(extractCoefficientExponent("(3x^2 + x - 3)"), extractCoefficientExponent("x-1"));
    printPolynomial(extractCoefficientExponent("(3x^2 + x - 3)")); 
    return 0;
}
