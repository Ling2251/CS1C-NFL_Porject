#include "NFL_input.h"

// Constructor
NFLInput::NFLInput()
{
    teamName = " ";
    stadiumName = " ";
    seatingCapacity = 0;
    location = " ";
    conference = " ";
    division = " ";
    surfaceType = " ";
    stadiumRoofType = " ";
    dateOpened = 0;
}

//Deconstructor
NFLInput::~NFLInput(){}

// opened the input file
void NFLInput::inputFn(QString fileName,NFLInput arr[], int size)
{
    // InconResource is the name of the resource file this project has
    Q_INIT_RESOURCE(InconResource);

    // declaring ifstram variable to handle input file
    QString line;

    // opening input file
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    int index = 0;	// loop control variable and array traversal
    QTextStream in(&file);
    // loop that traverses the array
    while (!in.atEnd() || index < size)
    {
        // read the data in one line at the time
        line = in.readLine();
        arr[index].teamName = line.toStdString();

        //read in the stadium Name
        line = in.readLine();
        arr[index].stadiumName = line.toStdString();

        //read in the seating caoacity
        line = in.readLine(); string line2 = line.toStdString();
        arr[index].seatingCapacity = stoi(line2);

        //read in the location
        line = in.readLine();
        arr[index].location = line.toStdString();

        //read in the conference
        line = in.readLine();
        arr[index].conference = line.toStdString();

        //read in the division
        line = in.readLine();
        arr[index].division = line.toStdString();

        //read in the surface Type
        line = in.readLine();
        arr[index].surfaceType = line.toStdString();

        //read in the stadium Roof Type
        line = in.readLine();
        arr[index].stadiumRoofType = line.toStdString();

        //read in the date Opened
        line = in.readLine(); line2 = line.toStdString();
        arr[index].dateOpened = stoi(line2);

        index++;
    }
    // closes input file
    file.close();
}

//Getter for the class
string NFLInput::getTeamName()
{
    return teamName;
}
string NFLInput::getStadiumName()
{
    return stadiumName;
}
int NFLInput::getSeatingCapacity()
{
    return seatingCapacity;
}
string NFLInput::getLocation()
{
    return location;
}
string NFLInput::getConference()
{
    return conference;
}
string NFLInput::getDivision()
{
    return division;
}
string NFLInput::getSurfaceType()
{
    return surfaceType;
}
string NFLInput::getStadiumRoofType()
{
    return stadiumRoofType;
}
int NFLInput::getDateOpened()
{
    return dateOpened;
}
