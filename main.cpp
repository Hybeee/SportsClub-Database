#include <iostream>

#define ELKESZULT 4

///header files
#include "gtest_lite.h"
#include "sports_club.h"
#include "database.hpp"

int main()
{
    /*///READFROMFILETEST
    std::ifstream in;

    in.open("club_data.txt");

    Database db;

    db.readFromFile(in);

    db.deleteElement(2);*/

    #if ELKESZULT >= 1
    ///Test 1. - Testing constructor -- default and constructor with parameters.
    TEST(Test1, DateTest)
    Date d1;

    std::cout << "Testing default constructor..." << std::endl;
    EXPECT_TRUE(d1 == Date());

    std::cout << "Testing constructor with parameters..." << std::endl;
    Date d2(2003, 1, 5);
    Date d3(2003, 1, 5);

    EXPECT_TRUE(d2 == d3);

    END

    ///-----------------------
    TEST(Test1.2, TrainerTest)
    Trainer t1;

    std::cout << "Testing default constructor..." << std::endl;
    EXPECT_TRUE(t1 == Trainer());

    std::cout << "Testing constructor with parameters..." << std::endl;
    Trainer t2("name", 3500, "kicks");
    Trainer t3("name", 3500, "kicks");

    EXPECT_TRUE(t2 == t3);
    END

    ///-----------------------
    TEST(Test1.3, PompomTest)
    PomPom p1;

    std::cout << "Testing default constructor..." << std::endl;
    EXPECT_TRUE(p1 == PomPom());

    std::cout << "Testing constructor with parameters..." << std::endl;
    PomPom p2("Girls", 5, 3.5);
    PomPom p3("Girls", 5, 3.5);

    EXPECT_TRUE(p2 == p3);
    END

    ///-----------------------
    TEST(Test1.5, FootballTest)
    Football f1;

    std::cout << "Testing default constructor..." << std::endl;
    EXPECT_TRUE(f1 == Football());

    std::cout << "Testing constructor with parameters..." << std::endl;
    Football f2("TEST", 420, Date(2000, 1, 1), "ColourTEST", Trainer("TrainerTEST", 2000, "AbilityTEST"), 20);
    Football f3("TEST", 420, Date(2000, 1, 1), "ColourTEST", Trainer("TrainerTEST", 2000, "AbilityTEST"), 20);

    EXPECT_TRUE(f2 == f3);

    END

    ///-----------------------
    TEST(Test1.6, BasketballTest)
    Basketball b1;

    std::cout << "Testing default constructor..." << std::endl;
    EXPECT_TRUE(b1 == Basketball());

    std::cout << "Testing constructor with parameters..." << std::endl;
    Basketball b2("TEST", 420, Date(2000, 1, 1), "ColourTEST", Trainer("TrainerTEST", 2000, "AbilityTEST"), PomPom("GirlsTEST", 10, 8.5));
    Basketball b3("TEST", 420, Date(2000, 1, 1), "ColourTEST", Trainer("TrainerTEST", 2000, "AbilityTEST"), PomPom("GirlsTEST", 10, 8.5));

    EXPECT_TRUE(b2 == b3);

    END

    ///-----------------------
    TEST(Test1.7, HandballTest)
    Handball h1;

    std::cout << "Testing default constructor..." << std::endl;
    EXPECT_TRUE(h1 == Handball());

    std::cout << "Testing constructor with parameters..." << std::endl;
    Handball h2("TEST", 420, Date(2000, 1, 1), "ColourTEST", Trainer("TrainerTEST", 2000, "AbilityTEST"), 2000);
    Handball h3("TEST", 420, Date(2000, 1, 1), "ColourTEST", Trainer("TrainerTEST", 2000, "AbilityTEST"), 2000);

    EXPECT_TRUE(h2 == h3);
    END

    #endif // ELKESZULT

    #if ELKESZULT >= 2
    ///Test 2. - Testing getter and setter functions for some of the classes.
    TEST(Test2.1, FootballTest)
    Football f1("TEST", 420, Date(2000, 1, 1), "ColourTEST", Trainer("TrainerTEST", 2000, "AbilityTEST"), 20);

    std::cout << "Testing setters..." << std::endl;

    f1.setName("TEST2");
    f1.setNumOfMembers(500);
    f1.setEst(Date(1000, 2, 2));
    f1.setColour("ColourTEST2");
    f1.setT(Trainer("TrainerTEST2", 1000, "AbilityTEST2"));
    f1.setStadiums(10);

    std::cout << "Testing getters..." << std::endl;

    EXPECT_TRUE(f1.getName() == "TEST2");
    EXPECT_TRUE(f1.getNumOfMembers() == 500);
    EXPECT_TRUE(f1.getEst() == Date(1000, 2, 2));
    EXPECT_TRUE(f1.getColour() == "ColourTEST2");
    EXPECT_TRUE(f1.getT() == Trainer("TrainerTEST2", 1000, "AbilityTEST2"));
    EXPECT_TRUE(f1.getStadiums() == 10);

    END

    ///-----------------------
    TEST(Test2.2, Basketball)
    Basketball b1("TEST", 420, Date(2000, 1, 1), "ColourTEST", Trainer("TrainerTEST", 2000, "AbilityTEST"), PomPom("GirlsTEST", 10, 8.5));

    std::cout << "Testing setters..." << std::endl;

    b1.setName("TEST2");
    b1.setNumOfMembers(500);
    b1.setEst(Date(1000, 2, 2));
    b1.setColour("ColourTEST2");
    b1.setT(Trainer("TrainerTEST2", 1000, "AbilityTEST2"));
    b1.setGirls(PomPom("GirlsTEST2", 20, 6.5));

    std::cout << "Testing getters..." << std::endl;

    EXPECT_TRUE(b1.getName() == "TEST2");
    EXPECT_TRUE(b1.getNumOfMembers() == 500);
    EXPECT_TRUE(b1.getEst() == Date(1000, 2, 2));
    EXPECT_TRUE(b1.getColour() == "ColourTEST2");
    EXPECT_TRUE(b1.getT() == Trainer("TrainerTEST2", 1000, "AbilityTEST2"));
    EXPECT_TRUE(b1.getGirls() == PomPom("GirlsTEST2", 20, 6.5));

    END

    ///-----------------------
    TEST(Test2.3, Handball)
    Handball h1("TEST", 420, Date(2000, 1, 1), "ColourTEST", Trainer("TrainerTEST", 2000, "AbilityTEST"), 2000);

    std::cout << "Testing setters..." << std::endl;

    h1.setName("TEST2");
    h1.setNumOfMembers(500);
    h1.setEst(Date(1000, 2, 2));
    h1.setColour("ColourTEST2");
    h1.setT(Trainer("TrainerTEST2", 1000, "AbilityTEST2"));
    h1.setFSupport(1000);

    std::cout << "Testing getters..." << std::endl;

    EXPECT_TRUE(h1.getName() == "TEST2");
    EXPECT_TRUE(h1.getNumOfMembers() == 500);
    EXPECT_TRUE(h1.getEst() == Date(1000, 2, 2));
    EXPECT_TRUE(h1.getColour() == "ColourTEST2");
    EXPECT_TRUE(h1.getT() == Trainer("TrainerTEST2", 1000, "AbilityTEST2"));
    EXPECT_TRUE(h1.getFSupport() == 1000);

    END
    #endif // ELKESZULT

    #if ELKESZULT >= 3
    ///Test 3. - Testing other operators (print, ++, --)
    TEST(Test3.1, PrintTest)

    Football f1("TEST", 420, Date(2000, 1, 1), "ColourTEST", Trainer("TrainerTEST", 2000, "AbilityTEST"), 20);
    f1.print(std::cout);

    f1++;
    ++f1;
    f1++;
    --f1;
    f1--;

    EXPECT_EQ(421, f1.getNumOfMembers());

    Basketball b1("TEST", 420, Date(2000, 1, 1), "ColourTEST", Trainer("TrainerTEST", 2000, "AbilityTEST"), PomPom("GirlsTEST", 10, 8.5));
    Handball h1("TEST", 420, Date(2000, 1, 1), "ColourTEST", Trainer("TrainerTEST", 2000, "AbilityTEST"), 2000);

    std::cout << std::endl;
    b1.print(std::cout);
    std::cout << std::endl;
    h1.print(std::cout);
    std::cout << std::endl;

    END
    #endif // ELKESZULT

    #if ELKESZULT >= 4
    ///Test 4. - Testing the heterogeneous collection. Subtests: ctor/dtor, reading from file(2 instances, one of them throws an error.), functions tested on a database that's been loaded from a file
    TEST(Test4.1, CtorDtorWithAddAndDelete)

    std::cout << "Testing constructor..." << std::endl;

    Database d1;

    EXPECT_EQ(size_t(0), d1.size());

    d1.addElement(new Football("TEST", 420, Date(2000, 1, 1), "ColourTEST", Trainer("TrainerTEST", 2000, "AbilityTEST"), 20));

    std::cout << "Testing new size after added element..." << std::endl;

    EXPECT_EQ(size_t(1), d1.size());

    Database d2 = d1;

    d2.addElement(new Handball("TEST", 420, Date(2000, 1, 1), "ColourTEST", Trainer("TrainerTEST", 2000, "AbilityTEST"), 2000));

    d1 = d2;

    std::cout << "Testing changes made to d1 and d2 after testing copy ctor and operator=..." << std::endl;

    EXPECT_EQ(size_t(2), d1.size());
    EXPECT_EQ(size_t(2), d2.size());

    END

    ///-----------------------
    TEST(Test4.2, FileHandle)

    try{
        std::cout << "Testing the correct file..." << std::endl;
        std::ifstream in;

        in.open("club_data.txt");

        Database db;
        db.readFromFile(in);
        db.printDataBase(std::cout, db.begin(), db.end());

        std::cout << "Deleting an element, saving it into a file, then re-reading that file and printing it..." << std::endl;

        db.deleteElement(2);

        std::ofstream out;
        out.open("club_data.txt");

        db.printToFile(out);

        db.readFromFile(in);

        db.printDataBase(std::cout, db.begin(), db.end());

        std::cout << "Now expecting an exception from the following read..." << std::endl;

        std::ifstream in2;
        in2.open("club_data_fault.txt");

        Database db2;
        db2.readFromFile(in2);

    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    END

    TEST(Test4.3, FileAndGeneralFunctions)

    try{
        std::ifstream in;

        in.open("club_data.txt");

        Database db;
        db.readFromFile(in);

        std::cout << "Testing print function with date functor..." << std::endl;
        db.printWithCondition(std::cout, db.begin(), db.end(), DateFunktor(Date(2000, 1, 1)));

        std::cout << "Testing count function with date functor..." << std::endl;
        int a = db.countWithCondition(db.begin(), db.end(), DateFunktor(Date(2002, 1, 1)));

        EXPECT_EQ(2, a);

        std::cout << "Testing deleteElement function..." << std::endl;
        db.deleteElement(2);

        EXPECT_EQ(size_t(2), db.size());

        std::cout << "Now deleting from an index that is out of bounds. Expecting throw..." << std::endl;

        db.deleteElement(2);

    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    END

    #endif // ELKESZULT

    return 0;
}
