#include <iostream>
#include <string>
#include "kennzeichen.hpp"
#include "database.hpp"

void schnapszahlTest()
{
    bool status;
    kfz::kennzeichen *carPlate = kfz::einlesen();
    status = kfz::istSchnapszahl(carPlate);
    std::string ort = carPlate->ort;
    std::string buchstaben = carPlate->buchstaben;
    short zahl = carPlate->zahl;

    if (status)
    {
        std::cout << "Your carplate: " << ort << "-" << buchstaben << "-" << zahl << " ,"
                  << "has Schnapszahl!" << std::endl;
    }
    else
    {
        std::cout << "Success! Your carplate is: " << ort << "-" << buchstaben << "-" << zahl << std::endl;
    }
}

void einlesenTest()
{
    kfz::kennzeichen *newPlate = kfz::einlesen();
    std::cout << kfz::ausgabe(*newPlate) << std::endl;
    kfz::schildTest(newPlate);
}

void databaseTest()
{
}

int main()
{
    //schnapszahlTest();
    einlesenTest();

    //kfz::testSchnapsZahl();
    
    return 0;
}