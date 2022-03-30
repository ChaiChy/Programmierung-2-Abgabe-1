#pragma once
#include <string>
#include <iostream>
#include <cassert>
#include <cstring>
/* IHR CODE */
namespace kfz
{
    struct Kennzeichen // kennzeichen = carplate
    {
        std::string ort;
        std::string buchstaben;
        short zahl;
    };

    typedef struct Kennzeichen kennzeichen;

    bool containsOnlyCapitalLetter(std::string stringInput)
    {
        for (int i = 0; i < stringInput.length(); i++)
        {
            if (stringInput[i] < 'A' || stringInput[i] > 'Z')
            {
                return false;
            }
        }
        return true;
    }
    std::string einlesenOrt() // readLocation
    {
        char input[10];
        while (true) // runs for eternity
        {
            std::cout << "Enter location: " << std::endl;
            std::cin >> input;

            if (!containsOnlyCapitalLetter(input))
            {
                std::cout << "Only capital letters!" << std::endl;
            }
            else if (strlen(input) <= 0 || strlen(input) > 3)
            {
                std::cout << "Number of letters must be between 1 to 3!" << std::endl;
            }
            else
            {
                return input;
            }

            std::cin.clear();  // clear error flag
            std::cin.ignore(); // clear input buffer
        };
    }

    std::string einlesenBuchstaben()
    {
        std::string input;
        while (true) // runs for eternity
        {
            std::cout << "Enter alphabet(s): " << std::endl;
            std::cin >> input;

            if (!containsOnlyCapitalLetter(input))
            {
                std::cout << "Only capital letters!" << std::endl;
            }
            else if (input.length() <= 0 || input.length() > 2)
            {
                std::cout << "Number of letters must be between 1 to 2!" << std::endl;
            }
            else
            {
                return input;
            }

            std::cin.clear();
            std::cin.ignore();
        };
    }
    short einlesenZahl()
    {
        short number;
        do
        {
            std::cout << "Enter number: " << std::endl;
            std::cin >> number;
            if (std::cin.fail()) // returns "true" when input != short (when input failure occurs)
            {
                std::cin.clear();  // clears error state of the buffer & prevents infinite loop of warnings
                std::cin.ignore(); // allows the input of a new number
                std::cout << "Invalid input, value must be a number between 1 - 9999!" << std::endl;
                continue;
            }

        } while (number <= 0 || number > 9999);

        return number;
    }
    kennzeichen *einlesen()
    {
        kennzeichen *plate = new kennzeichen;
        plate->ort = einlesenOrt();
        plate->buchstaben = einlesenBuchstaben();
        plate->zahl = einlesenZahl();
        return plate;
    }
    bool istSchnapszahl(const kennzeichen *pKennzeichen) // Schnapszahl = good luck number??
    {
        std::string temp;
        temp = std::to_string(pKennzeichen->zahl);
        if (temp.length() <= 1)
        {
            return false;
        }
        for (int i = 1; i < temp.length(); i++)
        {
            if (temp[i - 1] != temp[i])
                return false;
        }
        return true;
    }
    void testSchnapsZahl() // regression test/ unit test
    {
        kennzeichen kenn;
        kenn.zahl = 0;
        assert(istSchnapszahl(&kenn) == false);
        kenn.zahl = 1;
        assert(istSchnapszahl(&kenn) == false);
        kenn.zahl = 21;
        assert(istSchnapszahl(&kenn) == false);
        kenn.zahl = 212;
        assert(istSchnapszahl(&kenn) == false);
        kenn.zahl = 333;
        assert(istSchnapszahl(&kenn) == true);
        kenn.zahl = 11;
        assert(istSchnapszahl(&kenn) == true);
    }
    bool istZehner(const kennzeichen *pKennzeichen)
    {
        short temp = pKennzeichen->zahl;
        return ((temp % 10 == 0) && (temp >= 10) && (temp <= 90));
    }
    bool istHunderter(const kennzeichen &rKennzeichen)
    {
        short temp = rKennzeichen.zahl;
        return ((temp % 100 == 0) && (temp >= 100) && (temp <= 900));
    }
    bool istTausender(const kennzeichen *pKennzeichen)
    {
        short temp = pKennzeichen->zahl;
        return ((temp % 1000 == 0) && (temp >= 1000) && (temp <= 9000));
    }
    void schildTest(kennzeichen *schild)
    {
        if (istZehner(schild))
        {
            std::cout << "you have a Zehner! Great choice!" << std::endl;
        }
        else if (istHunderter(*schild))
        {
            std::cout << "you have a Hunderter! Very noice!" << std::endl;
        }
        else if (istTausender(schild))
        {
            std::cout << "wow you have a Tausender! UWU  " << std::endl;
        }
        else if (istSchnapszahl(schild))
        {
            std::cout << "Your carplate has a Schnapzahl!! " << std::endl;
        }
    }
    std::string ausgabe(const kennzeichen &rKennzeichen)
    {
        return rKennzeichen.ort + "-" + rKennzeichen.buchstaben + "-" + std::to_string(rKennzeichen.zahl);
    }
}
