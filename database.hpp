#pragma once
#define DB_LIMIT 10
#include "kennzeichen.hpp"
#include <string>
#include <sstream>

namespace db
{
    struct Database
    {
        std::string nameOfLocation;
        kfz::kennzeichen *schilder[DB_LIMIT]; // schilder = carplate
        int eintraege = 0;                    // entries
    };

    typedef struct Database database;
    bool einfuegen(database *db, kfz::kennzeichen *schild) // insert
    {
        
        for (int i = 0; i < DB_LIMIT; i++)
        {
            if (db->schilder[i] == NULL)
            {
                db->schilder[i] = schild;
                return true;
            }
        }
        return false;
    }
    std::string ausgabe(const database &db)
    {
        std::string newLine = "\n\n";
        std::string carplates;
        for (int i = 0; i < DB_LIMIT; i++)
        {
            carplates += kfz::ausgabe(*(db.schilder[i])) + newLine;
        }
        return "Database: " + db.nameOfLocation + newLine + "-------------" + newLine + carplates;
    }
}