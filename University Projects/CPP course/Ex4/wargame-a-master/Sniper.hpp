//Sniper will include his special ablilities
#include "Soldier.hpp"
#include <vector>
using namespace std;
namespace WarGame{
    class Sniper: public Soldier{

        public:
            Sniper(uint ID) : Soldier(ID,100,50){}
            void action(vector<vector<Soldier*>> &board,pair<int,int> sourceloc);
    };
}


