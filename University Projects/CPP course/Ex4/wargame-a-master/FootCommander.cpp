//FootCommander will include his special ablilities
#include "Soldier.hpp"
#include "FootCommander.hpp"
#include <vector>
#include <math.h>

using namespace std;

namespace WarGame{
                      void FootCommander::action(vector<vector<Soldier*>> &board,pair<int,int> sourceloc){
                   Soldier* source = board[sourceloc.first][sourceloc.second];
                   Soldier* target = nullptr;
                   double dis=board.size();
int i,j;
            for(int row=0; row < board.size();row++){
            for(int col=0;col<board[0].size();col++){
                   Soldier* p = board[row][col];
                if( p!=nullptr&&this->reID()!=p->reID()&&p!= source){
                 if(sqrt(pow(sourceloc.first-row,2)+pow(sourceloc.second-col,2))<dis){
                    dis=sqrt(pow(sourceloc.first-row,2)+pow(sourceloc.second-col,2));
                    target = board[row][col];
                              i = row;
                              j = col;
        }}}}
              if(target!=nullptr){
            target->dmg(this->DPA,i,j);
                if(target->Chp()==0){
        delete target;
        target=nullptr;
    }
        cout << "FC(" <<sourceloc.first <<","<<sourceloc.second<<") attacking an enemy soldier at ("<< i << "," << j << ")"<<endl;
              }  
            
            int r,c;
                std::pair<int,int> newloc;
                for(int r=0; r < board.size();r++){
            for(int c=0;c<board[0].size();c++){
                Soldier* b = board[r][c];
                newloc =make_pair(r,c);
                if( b!=nullptr&&this->reID()==b->reID()&&b!= source&&b->DPA==10){
                 b->action(board, newloc);
                }     
            }}
}
}
