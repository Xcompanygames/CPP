#include "doctest.h"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
using namespace std;

namespace WarGame {

    TEST_CASE("Test") {
        Board board(20, 20);
        CHECK(board.has_soldiers(1) == false);
        CHECK(board.has_soldiers(2) == false);
        CHECK(board.has_soldiers(3) == false);
        CHECK(board.has_soldiers(4) == false);
        CHECK(board.has_soldiers(5) == false);
        CHECK(board.has_soldiers(6) == false);
        board[{0, 1}] = new FootSoldier(1);
        board[{0, 2}] = new Sniper(1);
        board[{0, 3}] = new FootSoldier(1);
        board[{0, 4}] = new FootSoldier(1);
        board[{0, 6}] = new SniperCommander(1);
        CHECK(board.has_soldiers(1) == true);
        board[{5, 1}] = new FootSoldier(2);
        board[{5, 2}] = new Sniper(2);
        board[{5, 3}] = new FootSoldier(2);
        board[{5, 4}] = new FootSoldier(2);
        board[{5, 6}] = new SniperCommander(2);
        CHECK(board.has_soldiers(2) == true);
        CHECK_THROWS_AS(board.move(1, { 0,2 }, Board::MoveDIR::Down), std::invalid_argument);
        board.move(2, { 5,2 }, Board::MoveDIR::Right);
        board.move(2, { 5,3 }, Board::MoveDIR::Right);
        board.move(2, { 5,4 }, Board::MoveDIR::Right);
        board.move(2, { 5,5 }, Board::MoveDIR::Up);
        board[{4, 7}] = new Paramedic(1);
        board.move(2, { 0,4 }, Board::MoveDIR::Up);
        board.move(2, { 1,4 }, Board::MoveDIR::Up);
        board.move(2, { 1,5 }, Board::MoveDIR::Right);
        board.move(2, { 1,6 }, Board::MoveDIR::Right);
        board.move(2, { 1,7 }, Board::MoveDIR::Right);
        board.move(2, { 2,7 }, Board::MoveDIR::Up);
        board[{10, 10}] = new FootSoldier(1);
        board[{11, 11}] = new FootSoldier(1);
        board[{19, 19}] = new FootSoldier(2);
        board[{18, 11}] = new FootSoldier(2);

        //    board.move(1, { 10,10 }, Board::MoveDIR::Right);
         //   board.move(1, { 11,11 }, Board::MoveDIR::Right);
          //  board.move(2, { 19,19 }, Board::MoveDIR::Down);
           // board.move(2, { 18,19 }, Board::MoveDIR::Down);
        CHECK(board.has_soldiers(4) == false);
        CHECK(board.has_soldiers(5) == false);
        // board[{13, 7}] = new ParamedicCommander(1);
         //board.move(1, { 13,7 }, Board::MoveDIR::Right);
    }
}
