//mdn011
//2 December 2018
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::stoi;
using std::unordered_map;

void appearanceCount(string boxID, int & twoC, int & threeC) {
    unordered_map<string, int> ht;
    int twiceAppearances = 0; //1 if at least one character is counted twice
    int thriceApperances = 0; //1 if at least one character is counted thrice

    for (int i = 0; i < boxID.length(); i++) {
        string boxChar = boxID.substr(i, 1); //store first character of box ID
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

    for (auto it : ht) {
        if (it.second == 2) {
            twiceAppearances = 1;
        }
        if (it.second == 3) {
            thriceApperances = 1;
        }
    }

    if (twiceAppearances) {
        twoC += 1;
    }
    if (thriceApperances) {
        threeC += 1;
    }
    
}

int main() {
    //open text file containing input
    ifstream File("Day_2_input.txt");

    int twoCounts = 0;
    int threeCounts = 0;
    int checkSum = 0;

    if(File)
    {
        string input; //the input will be the box ID

        while(getline(File,input))
        {
            appearanceCount(input, twoCounts, threeCounts);
        }

    File.close();
    }

    checkSum = twoCounts * threeCounts;

    cout << checkSum << endl;
}