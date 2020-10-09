//FootSolider will include his special ablilities
#include "Soldier.hpp"
#include <vector>

namespace WarGame{
    class FootCommander: public Soldier{

        public:
            FootCommander(uint ID) : Soldier(ID,150,20){}
            void action(vector<vector<Soldier*>> &board,std::pair<int,int> target);
    };
}
