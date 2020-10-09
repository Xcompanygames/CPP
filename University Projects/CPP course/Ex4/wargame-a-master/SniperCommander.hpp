//SniperCommander will include his special ablilities
#include "Soldier.hpp"
#include <vector>

namespace WarGame{
    class SniperCommander: public Soldier{

        public:
            SniperCommander(uint ID) : Soldier(ID,120,100){}
            void action(vector<vector<Soldier*>> &board,std::pair<int,int> target);
    };
}
