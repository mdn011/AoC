//mdn011
//4 December 2018
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> // sort, set_intersection
#include <iomanip> // setw
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::vector;
using std::map;
using std::setw;

//reference stackoverflow 25961592
size_t matching_characters(string s1, string s2) {
  sort(begin(s1), end(s1));
  sort(begin(s2), end(s2));
  string intersection;
  set_intersection(begin(s1), end(s1), begin(s2), end(s2),
                        back_inserter(intersection));
  return intersection.size();
}

bool determine( string match1, string match2, size_t idLength )
{
    //cout << "comparing " << match1 << " with " << match2 << endl;
    unsigned int counter = 0;
    for (int i = 0; i < idLength; i++) 
    {
        string boxChar = match1.substr(i, 1); //store first character of box ID
        string boxChar2 = match2.substr(i, 1); //store first character of box ID
        
        if ( boxChar != boxChar2 )
        {
            counter++;
        }
    }

    counter -= 1; //subtract counter by 1. if only one mismatch found, returns false for the correct match

    return ( counter );
}

int main() {
    ifstream File( "Day_2_input.txt" ); //open text file containing input
    //ifstream File( "Day_2_example.txt" ); //open example text file
    const size_t idLength = 26; //box IDs all have length of 26 characters; example is 5
    const unsigned int sizeDiff = 1; //looking for a character difference of 1
    vector< string > boxIDs;
    string match1;
    string match2;
    map<string, int> ht;
    map<string, int> ht2;
    unsigned int position = 0; //store position of mismatching char

    if( File )
    {
        string input; //the input will be the box ID

        while( getline( File, input ) )
        {
            boxIDs.push_back( input );
        }

    File.close();
    }

    //cout << matching_characters( boxIDs[ 1 ], boxIDs[ 4 ] ) << endl;

    for ( unsigned int i = 0; i < boxIDs.size(); i++ ) 
    {
        for ( unsigned int j = i + 1; j < boxIDs.size(); j++ )
        {
            size_t matching = matching_characters( boxIDs[ i ], boxIDs[ j ] );
            if ( matching == (idLength - sizeDiff)  )
            {
                match1 = boxIDs[ i ];
                match2 = boxIDs[ j ];
                // cout << setw(30) << "first: " << boxIDs[i] << endl;
                // cout << setw(30) << "second: " << boxIDs[j] << endl;
                // cout << "difference: " << matching << endl;
                if ( determine( match1, match2, idLength ) ) 
                {
                    //cout << "no match" << endl;
                    continue;
                }
                else
                {
                    cout << "Found: " << endl;
                    cout << setw(30) << match1 << endl;
                    cout << setw(30) << match2 << endl;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < idLength; i++) {
        string boxChar = match1.substr(i, 1); //store first character of box ID
        int count = ht.count(boxChar); //store 1 or 0 if character already exists in box ID or not

        if (count < 1) {
            //cout << "inserting " << boxChar << "for " << boxID << "\n" << endl;
            ht.insert( {boxChar, 1}); //add unique char and appearance of 1     
        }
        else {
            //cout << "upping count for " << boxChar << " for " << boxID << "\n" << endl;
            ht.at(boxChar) += 1; //add 1 to the number of appearances for that unique char
        }
    }

    for (int i = 0; i < idLength; i++) {
        string boxChar = match2.substr(i, 1); //store first character of box ID
        int count = ht2.count(boxChar); //store 1 or 0 if character already exists in box ID or not

        if (count < 1) {
            //cout << "inserting " << boxChar << "for " << boxID << "\n" << endl;
            ht2.insert( {boxChar, 1}); //add unique char and appearance of 1     
        }
        else {
            //cout << "upping count for " << boxChar << " for " << boxID << "\n" << endl;
            ht2.at(boxChar) += 1; //add 1 to the number of appearances for that unique char
        }
    }

    cout << "the letters: " << endl;

    for ( auto it : ht )
    {
        if ( it.second == ht2[ it.first ] )
        {
            cout << it.first;
        }
    }
    cout << "\n Done." << endl;
} 