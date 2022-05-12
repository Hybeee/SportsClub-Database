#ifndef DATA_HANDLE_HPP_INCLUDED
#define DATA_HANDLE_HPP_INCLUDED

#include <iostream>
#include <sstream>
#include <vector>
#include <map>

#include "database.hpp"

/**
 DataHandle class - used to read SportsClub* from files and converts them to the correct type (Football, Basketball, Handball)
 */

class DataHandle {
  private:
    std::map<std::string, SportsClub*> prototypes;

  public:
    ~DataHandle() {
        std::map<std::string, SportsClub*>::iterator it;
        for (it = prototypes.begin(); it != prototypes.end(); ++it)
            delete it->second;
    }

    void proto_add(SportsClub* a, char const *nev) {
        prototypes[nev] = a;
    }

    /**Reads from a file*/
    /**Every child class is stored in a specific way - TypeofSportsClub otherdata*/
    /**Handles the conversion from SportsClub(ptr) to child class*/
    SportsClub* readFrom(std::istream& is) {
        std::string type;
        if (!(is >> type))
            return NULL;
        std::map<std::string, SportsClub*>::iterator it;
        it = prototypes.find(type);
        if (it == prototypes.end())
            throw std::runtime_error("invalid type!");

        SportsClub* proto = it->second;
        SportsClub* new_club = proto->clone();
        new_club->load(is);
        return new_club;
    }
};

#endif // DATA_HANDLE_HPP_INCLUDED
