#pragma once
#define DB_LIMIT 10
#include "kennzeichen.hpp"
#include <string>
#include <sstream>

namespace
{
    struct Database
    {
        std::string name;
        kfz::kennzeichen *schilder[DB_LIMIT]; // schilder = carplate
        int eintraege = 0;                    // entries
    };

    typedef struct Database database;
    bool einfuegen(database *db, kfz::kennzeichen *schild) // insert
    {
        db = new database;
        for (int i = 0; i < DB_LIMIT; i++) // set 0
        {
            db->schilder[i] = 0;
        }
        for (int i = 0; i < DB_LIMIT; i++)
        {
            if (db->schilder[i] == 0)
            {
                db->schilder[i] = schild;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    std::string ausgabe(const database &db)
    {
    }
}