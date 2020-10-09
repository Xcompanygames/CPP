//Soldier will include basic parameters
#include "Soldier.hpp"
#include <math.h>  
#include <vector>
namespace WarGame {
    void Soldier::heal(){
    CurrentHP=HP;
    }
     void Soldier::dmg(uint DPA,int x, int y){
        CurrentHP-=DPA;
        if(HP<=0){
            HP=0;
        }
                cout << "Solider was damaged by ";
                cout << DPA;
                cout << " at";
                cout <<  "("<< x << "," << y << ")";
                cout << "\n";

}
}
