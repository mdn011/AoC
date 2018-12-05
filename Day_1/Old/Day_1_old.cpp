//mdn011
//2 December 2018
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::stoi;

int main() 
{
    ifstream File( "Day_1_input.txt" ); //open text file containing input

    if( File )
    {
        string input; //the input will be "+" or "-" followed by an integer
        int frequency = 0; //to store the resulting frequency

        while(getline(File, input))
        {
            string drift = input.substr(0,1); //this will store the "+" or "-"
            int pos = input.find(drift); //position of drift
            string driftAmount = input.substr(pos + 1); //store the integer after drift
            if (drift == "+") {
                frequency += stoi(driftAmount); //add drift amount to resulting frequency
            }
            else {
                frequency -= stoi(driftAmount); //subtract drift amount to resulting freqnecy
            }
        }

        cout << frequency << endl;

    File.close();
    }
}