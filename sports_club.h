#ifndef SPORTS_CLUB_H_INCLUDED
#define SPORTS_CLUB_H_INCLUDED

/** This file is going to contain the parent/base and all 3 child/derived class (Football, Handball, Basketball)*/

/**include for std::string*/
#include <iostream>

/**includes of necessary files(date, trainer, pompom) for the data fields of the classes defined in this file*/
#include "date.h"
#include "trainer.h"
#include "pompom.h"

/**
 * SportsClub
 * The parent/base class (abstract)
 * Used in the heterogeneous container - database.h/.cpp
 */
class SportsClub{
protected:
    std::string name;
    int num_of_members;
    Date est;
    std::string colour;
    Trainer t;

public:
    SportsClub(std::string name = "",
               int num_of_members = 0,
               const Date& est = Date(),
               std::string colour = "",
               const Trainer& t = Trainer()): name(name),
                                              num_of_members(num_of_members),
                                              est(est),
                                              colour(colour),
                                              t(t) {}

    ///getter methods for each member variable
    std::string getName() const { return name; }
    int getNumOfMembers() const { return num_of_members; }
    const Date& getEst() const { return est; }
    std::string getColour() const { return colour; }
    const Trainer& getT() const { return t; }

    /**setter methods for each member variable*/
    void setName(std::string name) { this->name = name; } /**same as changeName method*/
    void setNumOfMembers(int num_of_members) { this->num_of_members = num_of_members; } /**sets the num of members to any given number.*/
    void setEst(const Date& est) { this->est = est; }
    void setColour(std::string colour) { this->colour = colour; }
    void setT(const Trainer &t) { this->t = t; }

    /**function to increment num_of_members with the operator ++/--. Pre- and Post-increment/decrement*/
    void operator++() { num_of_members++; }
    void operator++(int) { operator++(); }
    void operator--() { num_of_members--; }
    void operator--(int) { operator--(); }

    /**virtual print function
    uses the print function of member variables(ex.: << operator of Date, Trainer etc...)*/
    virtual void print(std::ostream& os) const = 0;

    /**functions for writing data into files / reading data from files*/
    virtual void save(std::ostream& os) const = 0; /**saves to file*/
    virtual void load(std::istream& is) = 0; /**reads from file*/
    virtual SportsClub* clone() const = 0; /**will be used when the heterogeneous collection reads from file*/

    virtual ~SportsClub() {}
};

/**Football team*/
class Football : public SportsClub{
    int stadiums;

public:
    Football(std::string name = "",
             int num_of_members = 0,
             const Date& est = Date(),
             std::string colour = "",
             const Trainer& t = Trainer(),
             int stadiums = 0): SportsClub(name, num_of_members, est, colour, t), stadiums(stadiums){}

    /**getter method for stadiums member variable*/
    int getStadiums() const { return stadiums; }

    /**setter method for stadiums member variable*/
    void setStadiums(int stadiums) { this->stadiums = stadiums; }

    /**function to test whether or not the setter/getter methods work in the test program*/
    bool operator==(const Football& rhs) const {
        return name == rhs.name &&
               num_of_members == rhs.num_of_members &&
               est == rhs.est &&
               colour == rhs.colour &&
               t == rhs.t &&
               stadiums == rhs.stadiums;
    }

    /**the functions that are virtual in parent class*/
    void print(std::ostream& os) const;

    /**file handler functions*/
    void save(std::ostream& os) const;
    void load(std::istream& is);
    Football* clone() const;

    ~Football() {}
};

/**Basketball team*/
class Basketball : public SportsClub{
    PomPom girls;

public:
    Basketball(std::string name = "",
             int num_of_members = 0,
             const Date& est = Date(),
             std::string colour = "",
             const Trainer& t = Trainer(),
             PomPom girls = PomPom()): SportsClub(name, num_of_members, est, colour, t), girls(girls) {}

    /**getter method for pompom*/
    const PomPom& getGirls() const { return girls; }

    /**setter method for pompom*/
    void setGirls(const PomPom& girls) { this->girls = girls; }

    /**function to test whether or not the setter/getter methods work in the test program*/
    bool operator==(const Basketball& rhs) const {
        return name == rhs.name &&
               num_of_members == rhs.num_of_members &&
               est == rhs.est &&
               colour == rhs.colour &&
               t == rhs.t &&
               girls == rhs.girls;
    }

    /**the functions that are virtual in parent class*/
    void print(std::ostream& os) const;

    /**file handler functions*/
    void save(std::ostream& os) const;
    void load(std::istream& is);
    Basketball* clone() const;

    ~Basketball() {}
};

/**Handball team*/
class Handball : public SportsClub{
    int fsupport;

public:
    Handball(std::string name = "",
             int num_of_members = 0,
             const Date& est = Date(),
             std::string colour = "",
             const Trainer& t = Trainer(),
             int fsupport = 0): SportsClub(name, num_of_members, est, colour, t), fsupport(fsupport) {}

    /**getter method for f_support*/
    int getFSupport() const { return fsupport; }

    /**setter method for f_support*/
    void setFSupport(int fsupport) { this->fsupport = fsupport; }

    /**function to test whether or not the setter/getter methods work in the test program*/
    bool operator==(const Handball& rhs) const {
        return name == rhs.name &&
               num_of_members == rhs.num_of_members &&
               est == rhs.est &&
               colour == rhs.colour &&
               t == rhs.t &&
               fsupport == rhs.fsupport;
    }

    /**the functions that are virtual in parent class*/
    void print(std::ostream& os) const;

    /**file handler functions*/
    void save(std::ostream& os) const;
    void load(std::istream& is);
    Handball* clone() const;


    ~Handball() {}
};

#endif // SPORTS_CLUB_H_INCLUDED
