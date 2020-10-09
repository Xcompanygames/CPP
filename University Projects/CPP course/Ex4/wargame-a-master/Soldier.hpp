//Soldier will include basic parameters
#pragma once
#include <iostream>
#include <vector>

using namespace std;
namespace WarGame {
    class Soldier{
        private:
   uint ID;
   uint CurrentHP;
   uint HP;  
public:
   uint DPA;
    Soldier(uint idnum, uint Current,uint DPA) : ID(idnum), CurrentHP(Current),HP(Current),DPA(DPA){}
    uint reID(){ return ID;} //player 1 or 2
    uint Chp(){ return CurrentHP;} //current hp
    uint CDPA(){ return DPA;} //current hp
    void heal();
    void dmg(uint DPA,int x, int y);
    virtual void action(vector<vector<Soldier*>> &board,std::pair<int,int> loc){;}
};
}
