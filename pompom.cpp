/**
 *
 * \file pompom.h
 *
 */

#include "pompom.h"

std::ostream& operator<<(std::ostream& os, const PomPom& rhs){
    return os << rhs.getName() << " "
              << rhs.getNumOfMembers() << " "
              << rhs.getRating();
}

std::istream& operator>>(std::istream& is, PomPom& rhs){
    std::string name;
    int num_of_members;
    float rating;

    is >> name >> num_of_members >> rating;

    rhs.setName(name);
    rhs.setNumOfMembers(num_of_members);
    rhs.setRating(rating);

    return is;
}
