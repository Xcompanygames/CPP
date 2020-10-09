//ParamedicCommander will include his special ablilities
#include "Soldier.hpp"
#include <vector>

namespace WarGame{
    class ParamedicCommander: public Soldier{

        public:
            ParamedicCommander(uint ID) : Soldier(ID,200,1000000){}
            void action(vector<vector<Soldier*>> &board,std::pair<int,int> target);
    };
}
