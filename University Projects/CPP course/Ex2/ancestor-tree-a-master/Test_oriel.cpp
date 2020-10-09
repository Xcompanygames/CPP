#include "doctest.h"
#include "FamilyTree.hpp"

using namespace family;

#include <string>
using namespace std;

TEST_CASE("Test 1 addFather & addMother & relation") {

    Tree T ("Robb");
    T.addFather("Robb", "Eddward").addMother("Robb", "Catelyn");

    CHECK(T.relation("Robb") == string("me"));
    CHECK(T.relation("Eddward") == string("father"));
    CHECK(T.relation("Catelyn") == string("mother"));

    CHECK_THROWS(T.addFather("Robb", "Robert")); //Robb already has Eddward as a father
    CHECK_THROWS(T.addMother("Robb", "Cersei")); //Robb already has Catelyn as a mother (well not too long)

    T.addMother("Eddward", "Lyanna").addFather("Lyanna", "Rickard");

    CHECK(T.relation("Lyanna") == string("grandmother"));
    CHECK(T.relation("Rickard") == string("great-grandfather"));
    CHECK_THROWS(T.addMother("Eddward", "Cersei"));
    CHECK_THROWS(T.addMother("Snow", "Catelyn"));  //snow isn't the son of anyone
    CHECK_THROWS(T.addFather("Nathan", "Robert")); 

    T.addFather("Eddward", "Brandon");
    CHECK(T.relation("Brandon") == string("grandfather"));

    //check case of searching name that doesn't exist on the tree 
    CHECK(T.relation("Deanerys") == string("unrelated"));
    CHECK(T.relation("Jorah") == string("unrelated"));
    CHECK(T.relation("Eva") == string("unrelated"));
    CHECK(T.relation("Shimon") == string("unrelated"));
    CHECK(T.relation("Yossi") == string("unrelated"));
}

TEST_CASE("Test 1 find") {

    Tree T ("Jon"); //Spoiler alert
    T.addFather("Jon", "Rhaegar").addMother("Jon", "Lyanna")
     .addFather("Rhaegar", "Aerys").addMother("Rhaegar", "Rhaella")
     .addFather("Aerys", "Jaehaerys").addMother("Aerys", "Shaera");

    CHECK(T.find("mother") == string("Lyanna"));
    CHECK(T.find("father") == string("Rhaegar"));
    CHECK((T.find("grandfather") == string("Aerys") || T.find("great-grandfather") == string("Jaehaerys")));
    CHECK((T.find("grandmother") == string("Rhaella") || T.find("great-grandmother") == string("Shaera")));
    CHECK_THROWS(T.find("uncle")); //there is no option of "uncle" on this tree
    CHECK_THROWS(T.find("sister")); 
    CHECK_THROWS(T.find("great-great-grandfather"));
    CHECK_THROWS(T.find("great-great-grandmother"));
    
    T.addMother("Jaehaerys", "Betha").addFather("Jaehaerys", "Aegon V").addFather("Aegon V", "Maekar I");

    CHECK(T.find("great-grandmother") == string("Betha"));
    CHECK(T.find("great-grandfather") == string("Aegon V"));
    CHECK(T.find("great-great-grandfather") == string("Maekar I"));
    CHECK_THROWS(T.find("great-great-grandmother"));
    CHECK_THROWS(T.find("great-great-great-grandfather"));
    CHECK_THROWS(T.find("great-great-great-great-grandfather"));
}

TEST_CASE("Test 1 remove") {

    Tree T ("Shireen");
    T.addMother("Shireen", "Selyse").addFather("Shireen", "Stannis")
     .addMother("Stannis", "Cassana ").addFather("Stannis", "Steffon")
     .addMother("Steffon", "Rhaelle").addFather("Steffon", "Ormund")
     .addFather("Rhaelle", "Aegon V");

    CHECK_THROWS(T.remove("Shireen")); 

    CHECK((T.find("grandfather") == string("Steffon")));

    CHECK(T.find("father") == string("Stannis"));
    T.remove("Stannis"); 
    CHECK_THROWS(T.find("father"));
	CHECK_THROWS(T.find("grandfather"));
	
}

TEST_CASE("Test 2 addFather & addMother & relation"){

    Tree T ("Bart");
    T.addFather("Bart", "Homer").addMother("Bart", "Marge");

    CHECK(T.relation("Bart") == string("me"));
    CHECK(T.relation("Homer") == string("father"));
    CHECK(T.relation("Marge") == string("mother"));
    CHECK(T.relation("Hugo") == string("unrelated"));
    CHECK(T.relation("Coco") == string("unrelated"));
    CHECK_THROWS(T.addFather("Bart", "Zeke")); // already has a father
    CHECK_THROWS(T.addMother("Bart", "Pippa"));
    
    T.addMother("Homer", "Mona").addFather("Homer", "Abraham").addFather("Abraham", "Orvile").addFather("Orvile", "Old Tut");

    CHECK(T.relation("Mona") == string("grandmother"));
    CHECK(T.relation("Orvile") == string("great-grandfather"));
    CHECK(T.relation("Abraham") == string("grandfather"));
    CHECK(T.relation("Old Tut") == string("great-great-grandfather"));

    CHECK_THROWS(T.addMother("Homer", "Carla")); // already has a mother
    CHECK_THROWS(T.addMother("Homer", "Lou"));

    CHECK_THROWS(T.addFather("Gonen", "a")); // not on the tree
    CHECK_THROWS(T.addFather("Gina", "b")); 


    CHECK_THROWS(T.addMother("Teva", "a")); // not in tree
    CHECK_THROWS(T.addMother("Toly", "b")); 
    CHECK_THROWS(T.addMother("Yonatan", "c"));
    CHECK_THROWS(T.addMother("Aaron", "d"));
    CHECK_THROWS(T.addMother("Norit", "e")); 

}

