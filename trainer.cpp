/**
 *
 * \file trainer.h
 *
 */

#include "trainer.h"

std::ostream& operator<<(std::ostream& os, const Trainer& rhs){
    return os << rhs.getName() << " "
              << rhs.getWage() << " "
              << rhs.getAbility();
}

std::istream& operator>>(std::istream& is, Trainer& rhs){
    std::string nname, nability;
    int nwage;

    is >> nname >> nwage >> nability;

    rhs.setName(nname);
    rhs.setWage(nwage);
    rhs.setAbility(nability);

    return is;
}
