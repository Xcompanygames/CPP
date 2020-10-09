//FootSolider will include his special ablilities
#include "Soldier.hpp"
#include <vector>
using namespace std;
namespace WarGame{
    class FootSoldier: public Soldier{

        public:
            FootSoldier(uint ID) : Soldier(ID,100,10){}
            void action(vector<vector<Soldier*>> &board,pair<int,int> sourceloc);
    };
}


