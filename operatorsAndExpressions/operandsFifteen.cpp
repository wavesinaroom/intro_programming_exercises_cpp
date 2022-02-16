#include <iostream>

using namespace std;

/* Write a program that exchanges the values of the bits on positions 
3, 4 and 5 with bits on positions 24, 25 and 26 of a given 32-bit 
unsigned integer */

int main(int argc, char const *argv[])
{
    unsigned int num;
    
    cout << "Swapping digits is fun!" << endl;
    cout << "Let's get started!" << endl;
    cout << "Please enter a number" << endl;

    cin >> num; 

    int bit3 = ((num >> 3) & 1); 
    int bit24 = ((num >> 24) & 1); 
    num = num & ((~(1 << 24)) | (bit3 << 24));
    num = num & ((~(1 << 3)) | (bit24 << 3)); 

    int bit4 = ((num >> 4) & 1); 
    int bit25 = ((num >> 25) & 1); 
    num = num & ((~(1 << 25)) | (bit3 << 25));
    num = num & ((~(1 << 4)) | (bit24 << 4)); 

    int bit5 = ((num >> 5) & 1); 
    int bit26 = ((num >> 26) & 1); 
    num = num & ((~(1 << 26)) | (bit3 << 26));
    num = num & ((~(1 << 5)) | (bit24 << 5)); 

    cout << "Your new number : " << num << endl;  
    
    return 0;
}

