#ifndef POMPOM_H_INCLUDED
#define POMPOM_H_INCLUDED

#include <iostream>

/**
 * PomPom girls
 * Will be a member variable in the Basketball class (child class of SprotsClub)
 */

class PomPom{
    std::string name;
    int num_of_members;
    float rating;

public:
    PomPom(std::string name = "", int num_of_members = 0, float rating = 0): name(name), num_of_members(num_of_members), rating(rating) {}

    /**getter methods for each member variable*/
    std::string getName() const { return name; }
    int getNumOfMembers() const { return num_of_members; }
    float getRating() const { return rating; }

    bool operator==(const PomPom& rhs) const {
        return (name == rhs.name) && (num_of_members == rhs.num_of_members) && (rating == rhs.rating);
    }

    /**setter methods for each member variable*/
    void setName(std::string name) { this->name = name; }
    void setNumOfMembers(int num_of_members) { this->num_of_members = num_of_members; }
    void setRating (float rating) { this->rating = rating; }

    ~PomPom() {}
};

/**function for printing 'PomPom' out to the standard output in the correct form*/
/**name: ..., num_of_members: ..., rating: ...*/
std::ostream& operator<<(std::ostream& os, const PomPom& rhs);

/**function for reading 'PomPom' from standard input*/
/**name wage ability*/
std::istream& operator>>(std::istream& is, PomPom& rhs);

#endif // POMPOM_H_INCLUDED
