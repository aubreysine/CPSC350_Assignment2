#include "Simulation.h"

class MirrorMode : public Simulation{
  public:
    MirrorMode();
    MirrorMode(int rows, int columns, float density);
    MirrorMode(ifstream &inFS);
    ~MirrorMode();

    typedef Simulation super; //Initialized super to call from inherited class(Simulation)

    void calcGen();
};
