#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;



TEST_CASE("Test Family1") {
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");

    CHECK_THROWS_AS(T.addMother("Shlomo", "Lea"), std::exception);
    CHECK_THROWS_AS(T.addFather("Shlomo", "Moshe"), std::exception);

    CHECK(T.relation("Yaakov") == string("father"));
    CHECK(T.relation("Rachel") == string("mother"));
    CHECK(T.relation("Isaac") == string("grandfather"));
    CHECK(T.relation("Rivka") == string("grandmother"));
    CHECK(T.relation("Avraham") == string("great-grandfather"));
    CHECK(T.relation("Terah") == string("great-great-grandfather"));
    CHECK(T.relation("Yosef") == string("me"));
    CHECK(T.relation("Tami") == string("unrelated"));
    

    CHECK(T.find("father") == string("Yaakov"));
    CHECK(T.find("mother") == string("Rachel"));
    CHECK(T.find("grandfather") == string("Isaac"));
    CHECK(T.find("grandmother") == string("Rivka"));
    CHECK(T.find("great-grandfather") == string("Avraham"));
    CHECK(T.find("great-great-grandfather") == string("Terah"));
    CHECK(T.find("me") == string("Yosef"));
    CHECK_THROWS_AS(T.find("great-grandmother"), std::exception);

    T.remove("Avraham");
    CHECK(T.relation("Avraham") == string("unrelated"));
    CHECK(T.relation("Terah") == string("unrelated"));
    CHECK_THROWS_AS(T.find("great-grandfather"), std::exception); 

}


TEST_CASE("Test Family2") {
    family::Tree T2 ("Shay"); 
	T2.addFather("Shay", "Mickey")   
	 .addMother("Shay", "Chani")   
	 .addFather("Chani", "Shmuel")
	 .addMother("Chani", "Shoshana")
	 .addFather("Mickey", "Gedalya")
	 .addMother("Mickey", "Rachel")
     .addFather("Gedalya" , "Asher")
     .addMother("Shoshana", "Esther");
     
     CHECK_THROWS_AS(T2.addMother("Shlomo", "Lea"), std::exception);
     CHECK_THROWS_AS(T2.addFather("Shlomo", "Moshe"), std::exception);

    
    CHECK(T2.relation("Mickey") == string("father"));
    CHECK(T2.relation("Chani") == string("mother"));
    CHECK(T2.relation("Shmuel") == string("grandfather"));
    CHECK(T2.relation("Shoshana") == string("grandmother"));
    CHECK(T2.relation("Gedalya") == string("grandfather"));
    CHECK(T2.relation("Rachel") == string("grandmother"));
    CHECK(T2.relation("Asher") == string("great-grandfather"));
    CHECK(T2.relation("Esther") == string("great-grandmother"));
    CHECK(T2.relation("Shay") == string("me"));
    CHECK(T2.relation("Roi") == string("unrelated"));
    

    CHECK(T2.find("father") == string("Mickey"));
    CHECK(T2.find("mother") == string("Chani"));
    CHECK(T2.find("great-grandfather") == string("Asher"));
    CHECK(T2.find("great-grandmother") == string("Esther"));
    CHECK(T2.find("me") == string("Shay"));
    CHECK_THROWS_AS(T2.find("great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(T2.find("brother"), std::exception);

    T2.remove("Shoshana");
    CHECK(T2.relation("Shoshana") == string("unrelated"));
    CHECK(T2.relation("Esther") == string("unrelated"));
    CHECK(T2.find("grandmother") == string("Rachel"));
    CHECK_THROWS_AS(T2.find("great-grandmother"), std::exception); 

}

TEST_CASE("Test Family3") {
    family::Tree T3 ("Noa"); 
	T3.addFather("Noa", "David")   
	 .addMother("Noa", "Sharon")   
	 .addFather("David", "Zvi")
	 .addMother("David", "Leah")
	 .addFather("Sharon", "Aryeh")
	 .addMother("Sharon", "Chaya")
     .addMother("Leah", "Miriam")
     .addFather("Chaya" , "Refael")
     .addFather("Refael", "Shlomo");

     CHECK_THROWS_AS(T3.addMother("Noa", "Galit"), std::exception);
     CHECK_THROWS_AS(T3.addFather("David", "Moshe"), std::exception);
     CHECK_THROWS_AS(T3.addFather("Roy", "David"), std::exception);
     CHECK_THROWS_AS(T3.addMother("Michal", "Sharon"), std::exception);

    
    CHECK(T3.relation("David") == string("father"));
    CHECK(T3.relation("Sharon") == string("mother"));
    CHECK(T3.relation("Zvi") == string("grandfather"));
    CHECK(T3.relation("Leah") == string("grandmother"));
    CHECK(T3.relation("Aryeh") == string("grandfather"));
    CHECK(T3.relation("Chaya") == string("grandmother"));
    CHECK(T3.relation("Refael") == string("great-grandfather"));
    CHECK(T3.relation("Miriam") == string("great-grandmother"));
    CHECK(T3.relation("Shlomo") == string("great-great-grandfather"));
    CHECK(T3.relation("Noa") == string("me"));
    CHECK(T3.relation("Roy") == string("unrelated"));
    

    CHECK(T3.find("father") == string("David"));
    CHECK(T3.find("mother") == string("Sharon"));

    CHECK(T3.find("great-grandfather") == string("Refael"));
    CHECK(T3.find("great-grandmother") == string("Miriam"));
    CHECK(T3.find("great-great-grandfather") == string("Shlomo"));
    CHECK(T3.find("me") == string("Noa"));
    CHECK_THROWS_AS(T3.find("great-great-grandmother"), std::exception);
    CHECK_THROWS_AS(T3.find("son"), std::exception);

    T3.remove("David");
    CHECK(T3.relation("David") == string("unrelated"));
    CHECK(T3.relation("Zvi") == string("unrelated"));
    CHECK(T3.relation("Leah") == string("unrelated"));
    CHECK(T3.relation("Miriam") == string("unrelated"));
    CHECK(T3.find("grandfather") == string("Aryeh"));
    CHECK(T3.find("grandmother") == string("Chaya"));
    CHECK_THROWS_AS(T3.find("great-grandmother"), std::exception);
    CHECK_THROWS_AS(T3.find("father"), std::exception); 

    T3.addFather("Noa","Moshe");
    CHECK(T3.find("father") == string ("Moshe"));
    CHECK(T3.relation("Moshe") == string("father"));
    CHECK(T3.relation("Leah") == string("unrelated"));

}

TEST_CASE("Test Family4") {
    family::Tree T4 ("Omer"); 
	T4.addFather("Omer", "Roni")   
	 .addFather("Roni", "Dani")   
	 .addFather("Dani", "Avi")
	 .addFather("Avi", "Moshe")
	 .addFather("Moshe", "Gabi")
	 .addFather("Gabi", "Roy");

    CHECK_THROWS_AS(T4.addFather("Omer", "Noam"), std::exception);
    CHECK_THROWS_AS(T4.addFather("Noam", "Joni"), std::exception);
    CHECK_THROWS_AS(T4.addFather("Dani", "Adam"), std::exception);

    CHECK(T4.relation("Roni") == string("father"));
    CHECK(T4.relation("Dani") == string("grandfather"));
    CHECK(T4.relation("Avi") == string("great-grandfather"));
    CHECK(T4.relation("Moshe") == string("great-great-grandfather"));
    CHECK(T4.relation("Gabi") == string("great-great-great-grandfather"));
    CHECK(T4.relation("Roy") == string("great-great-great-great-grandfather"));
  
    CHECK(T4.relation("Omer") == string("me"));
    CHECK(T4.relation("Tami") == string("unrelated"));
    

    CHECK(T4.find("father") == string("Roni"));
    CHECK(T4.find("grandfather") == string("Dani"));
    CHECK(T4.find("great-grandfather") == string("Avi"));
    CHECK(T4.find("great-great-grandfather") == string("Moshe"));
    CHECK(T4.find("great-great-great-grandfather") == string("Gabi"));
    CHECK(T4.find("great-great-great-great-grandfather") == string("Roy"));
    CHECK(T4.find("me") == string("Omer"));
    CHECK_THROWS_AS(T4.find("mother"), std::exception);
    CHECK_THROWS_AS(T4.find("grandmother"), std::exception);
    CHECK_THROWS_AS(T4.find("great-grandmother"), std::exception);
    CHECK_THROWS_AS(T4.find("great-great-grandmother"), std::exception);

    T4.remove("Roni");
    CHECK(T4.relation("Roni") == string("unrelated"));
    CHECK(T4.relation("Dani") == string("unrelated"));
    CHECK(T4.relation("Avi") == string("unrelated"));
    CHECK(T4.relation("Moshe") == string("unrelated"));
    CHECK(T4.relation("Gabi") == string("unrelated"));
    CHECK(T4.relation("Roy") == string("unrelated"));
    CHECK_THROWS_AS(T4.find("father"), std::exception);
    CHECK_THROWS_AS(T4.find("grandfather"), std::exception);
    CHECK_THROWS_AS(T4.find("great-grandfather"), std::exception); 
    CHECK_THROWS_AS(T4.find("great-great-grandfather"), std::exception);
    CHECK_THROWS_AS(T4.find("great=great-great-grandfather"), std::exception);
}