// Title: Parse and Validate data in File
// Purpose : Open file from user input, read data line by line and each numbers that represents win/s and loss/es
// Enjoy the process - Practice makes Improvement
// Author : Fransiskus Agapa
// Code outline : Zybook

#include <iostream>
#include <fstream>                            // deal with file
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::ifstream;
using std::string;

int main() {
    ifstream  in;
    string titleFile;
    string teamName;
    string fileName;
    int wins = 0;                                // good practice initializing with 0
    int loss = 0;
    int numTeam = 0;

    cout << endl << " Input the file name : " << endl;
    cin >> fileName;                             // input from user
    in.open(fileName);                        // can be hard code - put the file name directly inside in.open()

    if(!in.is_open())                            // check if file is opened
    {
        cout << " File is not exist " << endl;
        return 1;
    }

    getline(in , titleFile);              // read the first line - the title
    cout << endl << "  -- " << titleFile << " --" << endl << endl;

    getline(in, teamName);                // read team name until newline
    while(!in.fail())
    {
        numTeam++;
        in >> wins;                              // read num of win
        if(in.fail())
        {
            cout << numTeam << ". " << teamName << " has no win/s and loss/es " << endl << endl;
        } else
        {
            in >> loss;                           // read num of loss
            if(in.fail())
            {
                cout << numTeam << ". " << teamName << " has " << wins << " win/s" << endl << endl;
            } else
            {
                cout << numTeam << ". " << teamName << " has win average " << static_cast<double>(wins) / (wins + loss) << endl << endl;   //to double to include comma
            }
        }
        in.ignore();                                 // remove newline
        in.clear();                                  // erase content of string becomes empty string

      getline(in,teamName);                   // take next team name
    }
    in.close();                                      // done with file then close
    return 0;
}
