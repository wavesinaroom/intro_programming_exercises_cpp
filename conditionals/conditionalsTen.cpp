#include <iostream>

using namespace std;

/*Write a program the applies bonus points to given scores 
in the range of [1..9] by the following rules:
    -if the score is between 1 and 3, the program multiplies it by 10
    -if the score is between 4 and 6, the program multiplies it by 100
    -if the score is between 7 and 9, the program multiplies it by 1000
    -if the score is 0 or more than 9, the program prints an error message*/

int main(int argc, char const *argv[])
{
    int score;
    cout<<"Hi, let's see what score you get by selecting a number between 1 to 9"<<endl;
    cout<<"What's your number?"<<endl;
    cin>>score;

    /*Using this chain of if and else if statements reduces the amount of lines
    of code compared to choosing switch as a solution*/
     
    if (score>=1&&score<=3)
        cout<<"Your new score is: "<<score*10<<endl;
    else if (score>=4&&score<=6)
        cout<<"Your new score is: "<<score*100<<endl;
    else if (score>=7&&score<=9)
        cout<<"Your new score is: "<<score*1000<<endl;
    else
        cerr<<"That's not an option"<<endl;     

    return 0;
}

