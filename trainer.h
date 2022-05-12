#ifndef TRAINER_H_INCLUDED
#define TRAINER_H_INCLUDED

#include <iostream>

/**
 * Trainer
 * Will be a member variable in the SportsClub class
 */
class Trainer{
    std::string name;
    int wage;
    std::string ability; /**describes what the trainer helps the team with specifically ex.: shooting skills, defending skills etc...*/

public:
    Trainer(std::string name = "", int wage = 0, std::string ability = ""): name(name), wage(wage), ability(ability) {}

    /**getter methods for each member variable*/
    std::string getName() const { return name; }
    int getWage() const { return wage; }
    std::string getAbility() const { return ability; }

    bool operator==(const Trainer& rhs) const {
        return (name == rhs.name) && (wage == rhs.wage) && (ability == rhs.ability);
    }

    /**setter methods for each member variable*/
    void setName(std::string name) { this->name = name; }
    void setWage(int wage) { this->wage = wage; }
    void setAbility(std::string ability) { this->ability = ability; }

    ~Trainer() {}
};

/**function for printing 'Trainer' out to the standard output in the correct form*/
/**name: ..., wage: ..., ability: ...*/
std::ostream& operator<<(std::ostream& os, const Trainer& rhs);

/**function for reading 'Trainer' from standard input*/
/**name wage ability*/
std::istream& operator>>(std::istream& is, Trainer& rhs);

#endif // TRAINER_H_INCLUDED
