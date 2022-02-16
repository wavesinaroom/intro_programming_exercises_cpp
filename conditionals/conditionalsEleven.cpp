#include <iostream>

using namespace std;

/*Write a program that converts a number in the range [0..999] to words.
corresponding to the English language. Examples:
    - 0 --> "Zero"
    - 12 --> "Twelve"
    - 98 --> "Ninety eight"
    - 273 --> "Two hundred seventy three"
    - 400 --> "Four hundred"
    - 501 --> "Five hundred and one"
    - 711 --> "Seven hundred eleven" */

    int main(int argc, char const *argv[])
    {
        //Task is done albeit letter capitalization can improve... I'll leave it like that
        int number; 
        int digit;
        int tens;
        int hundreds; 

        string digitString;
        string tensString;
        string hundredsString;

        cout<<"Challenge me if I can put your number in words "<<endl;
        cin>>number; 
        if(number<0||number>999)
            cerr<<"That's not a valid number"<<endl; 

        //Hundreds
        hundreds = number/100; 
        //Tens of
        tens = (number%100)/10;
        //digit
        digit = number%10;


        if(((digit>0&&digit<10)&&tens==0)||((tens>1&&tens<10)&&digit==0))
        {
            switch (hundreds)
                {
                case 1:
                    hundredsString = "One hundred and ";
                    break;
                case 2:
                    hundredsString = "Two hundred and ";
                    break;
                case 3:
                    hundredsString = "Three hundred and ";
                    break;
                case 4:
                    hundredsString = "Four hundred and ";
                    break;
                case 5:
                    hundredsString = "Five hundred and ";
                    break;
                case 6:
                    hundredsString = "Six hundred and ";
                    break;
                case 7:
                    hundredsString = "Seven hundred and ";
                    break;
                case 8:
                    hundredsString = "Eight hundred and ";
                    break;
                case 9:
                    hundredsString = "Nine hundred and ";
                    break;
                }
        }else{
            switch (hundreds)
                {
                case 1:
                    hundredsString = "One hundred ";
                    break;
                case 2:
                    hundredsString = "Two hundred ";
                    break;
                case 3:
                    hundredsString = "Three hundred ";
                    break;
                case 4:
                    hundredsString = "Four hundred ";
                    break;
                case 5:
                    hundredsString = "Five hundred ";
                    break;
                case 6:
                    hundredsString = "Six hundred ";
                    break;
                case 7:
                    hundredsString = "Seven hundred ";
                    break;
                case 8:
                    hundredsString = "Eight hundred ";
                    break;
                case 9:
                    hundredsString = "Nine hundred ";
                    break;
                }
        }
        
        if (tens==1)
        {
            switch (digit)
                {
                case 0:
                    tensString = "Ten ";
                    break;
                case 1:
                    tensString = "Eleven ";
                    break;
                case 2:
                    tensString = "Twelve ";
                    break;
                case 3:
                    tensString = "Thirteen ";
                    break;
                case 4:
                    tensString = "Fourteen ";
                    break;
                case 5:
                    tensString = "Fifteen ";
                    break;
                case 6:
                    tensString = "Sixteen ";
                    break;
                case 7:
                    tensString = "Seventeen ";
                    break;
                case 8:
                    tensString = "Eighteen ";
                    break;
                case 9:
                    tensString = "Nineteen ";
                    break;
                }
        }else if(tens>=2)
        {
            switch (tens)
                {
                case 2:
                    tensString = "Twenty ";
                    break;
                case 3:
                    tensString = "Thirty ";
                    break;
                case 4:
                    tensString = "Fourty ";
                    break;
                case 5:
                    tensString = "Fifty ";
                    break;
                case 6:
                    tensString = "Sixty ";
                    break;
                case 7:
                    tensString = "Seventy ";
                    break;
                case 8:
                    tensString = "Eighty ";
                    break;
                case 9:
                    tensString = "Ninety ";
                    break;
                }
            //Digit
            switch (digit)
                {
                case 1:
                    digitString = "One";
                    break;
                case 2:
                    digitString = "Two";
                    break;
                case 3:
                    digitString = "Three";
                    break;
                case 4:
                    digitString = "Four";
                    break;
                case 5:
                    digitString = "Five";
                    break;
                case 6:
                    digitString = "Six";
                    break;
                case 7:
                    digitString = "Seven";
                    break;
                case 8:
                    digitString = "Eight";
                    break;
                case 9:
                    digitString = "Nine";
                    break;
                }
        }if(tens==0)
        {
            //Digit
            switch (digit)
            {
            case 1:
                digitString = "One";
                break;
            case 2:
                digitString = "Two";
                break;
            case 3:
                digitString = "Three";
                break;
            case 4:
                digitString = "Four";
                break;
            case 5:
                digitString = "Five";
                break;
            case 6:
                digitString = "Six";
                break;
            case 7:
                digitString = "Seven";
                break;
            case 8:
                digitString = "Eight";
                break;
            case 9:
                digitString = "Nine";
                break;
            }
        }
        
        cout<<hundredsString<<tensString<<digitString<<endl; 
        return 0;
    }
    
