//ParamedicCommander will include his special ablilities
#include "Soldier.hpp"
#include "ParamedicCommander.hpp"
#include <vector>
#include <math.h>

using namespace std;

namespace WarGame{
                   void ParamedicCommander::action(vector<vector<Soldier*>> &board,pair<int,int> sourceloc){
                   Soldier* source = board[sourceloc.first][sourceloc.second];
                   Soldier* target = nullptr;
                   double dis=board.size();
int i,j;
            for(int row=0; row < board.size();row++){
            for(int col=0;col<board[0].size();col++){
                   Soldier* p = board[row][col];
                if( p!=nullptr&&this->reID()!=p->reID()&&p!= source){
                if((abs(row-sourceloc.first)==0&&abs(col-sourceloc.second)==1)||(abs(row-sourceloc.first)==1&&abs(col-sourceloc.second)==0)||(abs(row-sourceloc.first)==1&&abs(col-sourceloc.second)==1)){
                        p->heal();
                 cout << "ParamedicCommander(" <<sourceloc.first <<","<<sourceloc.second<<") Heal a soldier at ("<< row << "," << col << ")"<<endl;

        }}}}
 
            
            int r,c;
                std::pair<int,int> newloc;
                for(int r=0; r < board.size();r++){
            for(int c=0;c<board[0].size();c++){
                Soldier* b = board[r][c];
                newloc =make_pair(r,c);
                if( b!=nullptr&&this->reID()==b->reID()&&b!= source&&b->DPA==100000){
                 b->action(board, newloc);
                }     
            }}
}
}
