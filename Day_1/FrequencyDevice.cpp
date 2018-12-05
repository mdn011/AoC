//mdn011
//2 December 2018
#include <iostream>
#include <algorithm> //find_if
#include <assert.h>
#include "FrequencyDevice.h"
using std::stoi;
using std::find_if;
using std::isdigit;
using std::to_string;

/*----------------------------------------------*/
/*      CONSTRUCTORS                            */
/*----------------------------------------------*/

FrequencyDevice::FrequencyDevice()
    : frequency( 0 ), drift( "+" ), position( 0 ), driftAmount( "0" )
{
    //initialize freqOccurrences key of 0 to value of 1, since counts as first occurrence
    freqOccurrences.insert( { "0", 1 } );
}

FrequencyDevice::FrequencyDevice( string input )
    : frequency( 0 )
{
    setDrift( input );
    setPosition( input );
    setDriftAmount( input, position );
}

/*----------------------------------------------*/
/*      MUTATORS                                */
/*----------------------------------------------*/

void FrequencyDevice::setFrequency( string drift, string driftAmount )
{
    if ( drift == "+" ) 
    {
        frequency += stoi( driftAmount ); //add drift amount to resulting frequency
    }
    else
    {
        frequency -= stoi( driftAmount ); //subtract drift amount to resulting freqnecy
    }
}

void FrequencyDevice::setDrift( string input )
{
    drift = input.substr( 0, 1 ); //this will store the "+" or "-"
    assert( drift == "+" || drift == "-" );
}

void FrequencyDevice::setPosition( string input )
{
    position = input.find(drift); //position of drift
}

void FrequencyDevice::setDriftAmount( string input, int position )
{
    int startPosition = position + 1; //set the start position at one character after the drift position
    driftAmount = input.substr( startPosition ); //store the integer after drift
    assert( is_number( driftAmount ) );
}

void FrequencyDevice::setFreqOccurrences( int frequency )
{
    string frequencyKey = to_string( frequency );
    int count = freqOccurrences.count( frequencyKey ); //get 1 or 0 if frequency already exists or not

    if (count < 1) 
    {
        freqOccurrences.insert( { frequencyKey, 1 } ); //add frequency and counter of 1    
    }
    else 
    {
        freqOccurrences.at( frequencyKey ) += 1; //add 1 to the frequency's counter
    }
}

/*----------------------------------------------*/
/*      ACCESSORS                               */
/*----------------------------------------------*/

int FrequencyDevice::getFrequency() const
{
    return frequency;
}

string FrequencyDevice::getDrift() const
{
    return drift;
}

int FrequencyDevice::getPosition() const
{
    return position;
}

string FrequencyDevice::getDriftAmount() const
{
    return driftAmount;
}

int FrequencyDevice::getFreqOccurrences( int frequency ) const
{
    string frequencyKey = to_string( frequency );
    return freqOccurrences.at( frequencyKey );
}

/*----------------------------------------------*/
/*      OTHERS                                  */
/*----------------------------------------------*/

bool FrequencyDevice::is_number( const string & s )
{   //reference stackoverflow 4654636
    //only works for positive integers
    return !s.empty() && find_if( s.begin(), s.end(), []( char c ) { return !isdigit( c ); } ) == s.end();
}