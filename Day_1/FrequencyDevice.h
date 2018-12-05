//mdn011
//2 December 2018
#include <string>
#include <map>
using std::string;
using std::map;

class FrequencyDevice
{
public:
    //Constructors
    FrequencyDevice();
    explicit FrequencyDevice( string );

    //Mutators
    void setFrequency( string, string );
    void setDrift( string );
    void setPosition( string );
    void setDriftAmount( string, int );
    void setFreqOccurrences( int );

    //Accessors
    int getFrequency() const;
    string getDrift() const;
    int getPosition() const;
    string getDriftAmount() const;
    int getFreqOccurrences( int ) const;

    //Others
    bool is_number( const string & );

private:
    string drift;
    string driftAmount;
    int position;
    int frequency;
    map<string, int> freqOccurrences;
};