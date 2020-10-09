//Paramedic will include his special ablilities
#include "Soldier.hpp"
#include <vector>
using namespace std;
namespace WarGame{
    class Paramedic: public Soldier{
        public:
            Paramedic(uint ID) : Soldier(ID,100,100000){}
            void action(vector<vector<Soldier*>> &board,pair<int,int> sourceloc);
    };
}

