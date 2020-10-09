#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include "Board.hpp"
using namespace std;


namespace WarGame {

    // operator for putting soldiers on the game-board during initialization.
    Soldier*& Board::operator[](pair<int,int> location){
        
      if(startgame==false){
       cout << "S(" <<location.first <<","<<location.second<<") was placed"<<endl;
       }
      return board[location.first][location.second];
    }
    
    // operator for reading which soldiers are on the game-board.
    Soldier* Board::operator[](pair<int,int> location) const{
      return board[location.first][location.second];
    }
    
    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument". 
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null); V
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers 
    //      must be handled by polymorphism.
    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
        cout << "Input: "<<endl;

        switch(direction)
{
    case Up  : std::cout << "Up\n";   break;
    case Down: std::cout << "Down\n"; break;
    case Right : std::cout << "Right\n";  break;
    case Left: std::cout << "Left\n"; break;
}        
        startgame=true;

      Soldier *a = board[source.first][source.second];
      if(a==nullptr){
     throw invalid_argument("There is no soldier in the source location");
      }
      if(player_number!=a->reID()){
               throw invalid_argument("The soldier in the source location belongs to the other player.");
      }
        std::pair<int,int> sourceloc;

       if(direction==Down&&source.first-1>0&&board[source.first-1][source.second]==nullptr){
        cout << "S(" <<source.first <<","<<source.second<<")Went down"<<endl;
        board[source.first-1][source.second]=a;
        cout << "S(" <<source.first-1 <<","<<source.second<<")Current Position"<<endl;
        board[source.first][source.second]=nullptr;
        sourceloc =make_pair(source.first-1,source.second);
        a->action(board, sourceloc);
      }else if(direction==Down&&source.first-1<0){
        throw invalid_argument("Can't move out of the board.");
      }
       if(direction==Up&&board[source.first+1][source.second]==nullptr){
        cout << "S(" <<source.first <<","<<source.second<<")Went up"<<endl;
        board[source.first+1][source.second]=a;
        cout << "S(" <<source.first+1 <<","<<source.second<<")Current Position"<<endl;
        board[source.first][source.second]=nullptr;
        sourceloc =make_pair(source.first+1,source.second);
       a->action(board, sourceloc);
      }else if(direction==Up&&source.first+1>board.size()){
        throw invalid_argument("Can't move out of the board.");
      }

       if(direction==Left&&board[source.first][source.second-1]==nullptr){
        cout << "S(" <<source.first <<","<<source.second<<")Went left"<<endl;
        board[source.first][source.second-1]=a;
        cout << "S(" <<source.first <<","<<source.second-1<<")Current Position"<<endl;
        board[source.first][source.second]=nullptr;
        sourceloc =make_pair(source.first,source.second-1);
        a->action(board, sourceloc);
      }else if(direction==Left&&source.second-1<0){
        throw invalid_argument("Can't move out of the board.");
      }
        
       if(direction==Right&&board[source.first][source.second+1]==nullptr){
        cout << "S(" <<source.first <<","<<source.second<<")Went right"<<endl;
        board[source.first][source.second+1]=a;
        cout << "S(" <<source.first <<","<<source.second+1<<")Current Position"<<endl;
        board[source.first][source.second]=nullptr;
        sourceloc =make_pair(source.first,source.second+1);
        a->action(board, sourceloc);
      }else if(direction==Right&&source.second+1>board.size()){
        throw invalid_argument("Can't move out of the board.");
      }


    }

    // returns true iff the board contains one or more soldiers of the given player.
    bool Board::has_soldiers(uint player_number) const{
        for(int row=0; row < board.size();row++){
            for(int col=0;col<board[0].size();col++)
                if(board[row][col] != nullptr && board[row][col]->reID() == player_number && board[row][col]->Chp()!=0)
                    return true;
        }
        return false;
    }

}

