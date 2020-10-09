/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "haPPi") == string("Happi"));
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "haPpi") == string("Happi"));
    CHECK(find(text, "hAppi") == string("Happi"));
    CHECK(find(text, "hAppI") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
}
TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "xxx dont yyy";
    CHECK(find(text, "dont") == string("dont"));
    CHECK(find(text, "Dont") == string("dont"));
    CHECK(find(text, "dOnt") == string("dont"));
    CHECK(find(text, "doNt") == string("dont"));
    CHECK(find(text, "donT") == string("dont"));
    CHECK(find(text, "DOnt") == string("dont"));
    CHECK(find(text, "DONt") == string("dont"));
    CHECK(find(text, "DONT") == string("dont"));
    CHECK(find(text, "DoNt") == string("dont"));
    CHECK(find(text, "DonT") == string("dont"));
    CHECK(find(text, "dONt") == string("dont"));
    CHECK(find(text, "DoNT") == string("dont"));
}
TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "xxx dond yyy";
    CHECK(find(text, "dond") == string("dond"));
    CHECK(find(text, "Dond") == string("dond"));
    CHECK(find(text, "dOnd") == string("dond"));
    CHECK(find(text, "doNd") == string("dond"));
    CHECK(find(text, "donD") == string("dond"));
    CHECK(find(text, "DOnd") == string("dond"));
    CHECK(find(text, "DONd") == string("dond"));
    CHECK(find(text, "DOND") == string("dond"));
    CHECK(find(text, "dONd") == string("dond"));
    CHECK(find(text, "dOND") == string("dond"));
    CHECK(find(text, "doND") == string("dond"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "xxx be yyy";
    CHECK(find(text, "be") == string("be"));
    CHECK(find(text, "Be") == string("be"));
    CHECK(find(text, "bE") == string("be"));
    CHECK(find(text, "BE") == string("be"));

}
TEST_CASE("Test replacement of b and f and p in be") {
    string text = "xxx be yyy";
    CHECK(find(text, "fe") == string("be"));
    CHECK(find(text, "be") == string("be"));
    CHECK(find(text, "pe") == string("be"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "xxx worri yyy";
    CHECK(find(text, "worri") == string("worri"));
    CHECK(find(text, "Worri") == string("worri"));
    CHECK(find(text, "wOrri") == string("worri"));
    CHECK(find(text, "woRri") == string("worri"));
    CHECK(find(text, "wOrRi") == string("worri"));
    CHECK(find(text, "worrI") == string("worri"));
    CHECK(find(text, "WOrri") == string("worri"));
    CHECK(find(text, "WORri") == string("worri"));
    CHECK(find(text, "WORRi") == string("worri"));
    CHECK(find(text, "WORRI") == string("worri"));
    CHECK(find(text, "worRI") == string("worri"));
    CHECK(find(text, "woRRI") == string("worri"));
    CHECK(find(text, "wORRI") == string("worri"));
}
TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "xxx haffy yyy";
    CHECK(find(text, "haffy") == string("haffy"));
    CHECK(find(text, "Haffy") == string("haffy"));
    CHECK(find(text, "hAffy") == string("haffy"));
    CHECK(find(text, "haFfy") == string("haffy"));
    CHECK(find(text, "hafFy") == string("haffy"));
    CHECK(find(text, "haffY") == string("haffy"));
    CHECK(find(text, "HAffy") == string("haffy"));
    CHECK(find(text, "HAFfy") == string("haffy"));
    CHECK(find(text, "HAFFy") == string("haffy"));
    CHECK(find(text, "HAFFY") == string("haffy"));
    CHECK(find(text, "HaFfy") == string("haffy"));
    CHECK(find(text, "HafFy") == string("haffy"));
    CHECK(find(text, "HaffY") == string("haffy"));
    CHECK(find(text, "haFFy") == string("haffy"));


}


TEST_CASE("Test replacement of v and w, i and y, o and u in worry") {
    string text = "xxx worry yyy";
    CHECK(find(text, "worry") == string("worry"));
    CHECK(find(text, "vorri") == string("worry"));
    CHECK(find(text, "worri") == string("worry"));
    CHECK(find(text, "wurry") == string("worry"));
    CHECK(find(text, "wurri") == string("worry"));
    CHECK(find(text, "vurry") == string("worry"));
    CHECK(find(text, "vorry") == string("worry"));

}

TEST_CASE("Test replacement of o and u, d and t in dont") {
    string text = "xxx dont yyy";
    CHECK(find(text, "dont") == string("dont"));
    CHECK(find(text, "tont") == string("dont"));
    CHECK(find(text, "tunt") == string("dont"));
    CHECK(find(text, "tund") == string("dont"));
    CHECK(find(text, "dond") == string("dont"));
    CHECK(find(text, "dund") == string("dont"));
    CHECK(find(text, "dunt") == string("dont"));

}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "xxx worry yyy";
    CHECK(find(text, "worry") == string("worry"));
    CHECK(find(text, "Worry") == string("worry"));
    CHECK(find(text, "wOrry") == string("worry"));
    CHECK(find(text, "woRry") == string("worry"));
    CHECK(find(text, "worRy") == string("worry"));
    CHECK(find(text, "worrY") == string("worry"));
    CHECK(find(text, "WOrry") == string("worry"));
    CHECK(find(text, "WORry") == string("worry"));
    CHECK(find(text, "WORRy") == string("worry"));
    CHECK(find(text, "WORRY") == string("worry"));
    CHECK(find(text, "WoRry") == string("worry"));
    CHECK(find(text, "WorRy") == string("worry"));
    CHECK(find(text, "WorRY") == string("worry"));
    CHECK(find(text, "worRY") == string("worry"));
    CHECK(find(text, "woRRy") == string("worry"));
    CHECK(find(text, "wORRy") == string("worry"));
    CHECK(find(text, "wORry") == string("worry"));
}
TEST_CASE("Test replacement of p and f and b, i and y in happy") {
    string text = "xxx happy yyy";
    CHECK(find(text, "hafpy") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "habfy") == string("happy"));
    CHECK(find(text, "hafby") == string("happy"));
    CHECK(find(text, "hafpi") == string("happy"));
    CHECK(find(text, "hapfi") == string("happy"));
    CHECK(find(text, "haffi") == string("happy"));
    CHECK(find(text, "habpi") == string("happy"));
    CHECK(find(text, "hapbi") == string("happy"));
    CHECK(find(text, "habbi") == string("happy"));
    CHECK(find(text, "habfi") == string("happy"));
    CHECK(find(text, "hafbi") == string("happy"));
}
