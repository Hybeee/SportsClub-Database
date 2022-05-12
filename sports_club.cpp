/**
 *
 * \file sports_club.h
 *
 */

#include "sports_club.h"

/**Football team*/

/**Used to print data of the football team to the console*/
void Football::print(std::ostream& os) const {
    os << "Football team: " << std::endl
       << "Name: " << name << std::endl
       << "Number of members: " << num_of_members << std::endl
       << "Established in: " << est << std::endl
       << "Colour: " << colour << std::endl
       << "Trainer: " << t << std::endl
       << "Number of stadiums: " << stadiums << std::endl;
}

/**Used to print data of the football team to a file*/
void Football::save(std::ostream& os) const {
    os << "Football "
       << name << " "
       << num_of_members << " "
       << est << " "
       << colour << " "
       << t << " "
       << stadiums;
}
void Football::load(std::istream& is) {
    is >> name >> num_of_members >> est >> colour >> t >> stadiums;
}

/**clone function - used in database.cpp -> readDataBase(...)*/
Football* Football::clone() const { return new Football(*this); }

/**Basketball team*/

/**Used to print data of the basketball team to a console*/
void Basketball::print(std::ostream& os) const {
    os << "Basketball team: " << std::endl
       << "Name: " << name << std::endl
       << "Number of members: " << num_of_members << std::endl
       << "Established in: " << est << std::endl
       << "Colour: " << colour << std::endl
       << "Trainer: " << t << std::endl
       << "PomPom girls: " << girls << std::endl;
}

/**Used to print data of the basketball team to a file*/
void Basketball::save(std::ostream& os) const {
    os << "Basketball "
       << getName() << " "
       << num_of_members << " "
       << est << " "
       << colour << " "
       << t << " "
       << girls;
}
void Basketball::load(std::istream& is) {
    is >> name >> num_of_members >> est >> colour >> t >> girls;
}

/**clone function - used in database.cpp -> readDataBase(...)*/
Basketball* Basketball::clone() const { return new Basketball(*this); }

/**Handball team*/

/**Used to print data of the handball team to the console*/
void Handball::print(std::ostream& os) const {
    os << "Handball team: " << std::endl
       << "Name: " << name << std::endl
       << "Number of members: " << num_of_members << std::endl
       << "Established in: " << est << std::endl
       << "Colour: " << colour << std::endl
       << "Trainer: " << t << std::endl
       << "Financial support: " << fsupport << "$" << std::endl;
}

/**Used to print data of the handball team to a file*/
void Handball::save(std::ostream& os) const {
    os << "Handball "
       << name << " "
       << num_of_members << " "
       << est << " "
       << colour << " "
       << t << " "
       << fsupport;
}
void Handball::load(std::istream& is) {
    is >> name >> num_of_members >> est >> colour >> t >> fsupport;
}

/**clone function - used in database.cpp -> readDataBase(...)*/
Handball* Handball::clone() const { return new Handball(*this); }
