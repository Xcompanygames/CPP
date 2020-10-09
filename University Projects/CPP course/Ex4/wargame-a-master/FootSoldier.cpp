//FootSolider will include his special ablilities
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include <vector>
#include <math.h>

using namespace std;

namespace WarGame{
            void FootSoldier::action(vector<vector<Soldier*>> &board,pair<int,int> sourceloc){
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
         cout <<i;
         cout <<")";
         cout <<",";
         cout <<j;
         cout <<")";
         cout <<" is dead\n";
        delete target;
        target=nullptr;
    }
           
               
        cout << "FS(" <<sourceloc.first <<","<<sourceloc.second<<") attacking an enemy soldier at ("<< i << "," << j << ")"<<endl;
                       cout << target->Chp();
         cout <<" left to attacked soldier\n";

              }  
            }

}
