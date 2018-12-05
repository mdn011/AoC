//mdn011
//2 December 2018
#include <iostream>
#include <fstream>
#include "FrequencyDevice.h"
using std::cout;
using std::endl;
using std::ifstream;
using std::getline;

int main() 
{
    ifstream File( "Day_1_input.txt" ); //open text file containing input
    FrequencyDevice device1;
    int firstDuplicate = 0; //store the first duplicate frequency
    bool duplicateFound = false;
    int firstFinalFrequency = 0; //store the resulting frequency value after reading file only once
    int fileReadCounter = 0; //number of times file has been read

    if( File )
    {
        string input; //the input will be "+" or "-", followed by an integer

        while ( !duplicateFound )
        {
            while( getline( File, input ) )
            {
                device1.setDrift( input );
                string drift = device1.getDrift();
                device1.setPosition( input );
                int position = device1.getPosition();
                device1.setDriftAmount( input, position );
                string driftAmount = device1.getDriftAmount();
                device1.setFrequency( drift, driftAmount );

                device1.setFreqOccurrences( device1.getFrequency() );
                int count = device1.getFreqOccurrences( device1.getFrequency() );
                if ( count > 1 && duplicateFound == false )
                {
                    firstDuplicate = device1.getFrequency();
                    duplicateFound = true;
                }
            }

            if ( fileReadCounter == 0 )
            {
                firstFinalFrequency = device1.getFrequency();
            }

            fileReadCounter++;

            if ( !duplicateFound )
            {
                File.clear();
                File.seekg( 0, std::ios::beg );
            }
        }

        cout << "The final frequency is: " << firstFinalFrequency << "\n"
        "The first duplicate frequency is: " << firstDuplicate << endl;

    File.close();
    }
}