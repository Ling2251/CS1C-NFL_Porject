#ifndef NFL_INPUT_H
#define NFL_INPUT_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <QFile>
using namespace std;

const int AR_SIZE = 32;

// This class will opened the input file and read in the data section by section and put
// them into the right loaction of an array
class NFLInput
{
private:
    string teamName;        /// Stores team names.
    string stadiumName;     /// Stores team Stadiums name.
    int seatingCapacity;    /// Stores team Stadiums seating capacity.
    string location;        /// Stores team location.
    string conference;      /// Stores team conference.
    string division;        /// Stores team division.
    string surfaceType;     /// Stores team stadium surface types.
    string stadiumRoofType; /// Stores team stadium roof types.
    int dateOpened;         /// Stores team stadium date opened.
public:
    NFLInput();

    ~NFLInput();

    void inputFn(QString fileName, NFLInput arr[], int size);

    // getter to return the data.
    std::string getTeamName();
    std::string getStadiumName();
    int getSeatingCapacity();
    std::string getLocation();
    std::string getConference();
    std::string getDivision();
    std::string getSurfaceType();
    std::string getStadiumRoofType();
    int getDateOpened();
};


#endif // NFL_INPUT_H
