#include "Simulation.h"

class MirrorMode : public Simulation{
  public:
    MirrorMode();
    MirrorMode(int rows, int columns, float density);
    MirrorMode(string fName);
    ~MirrorMode();

    typedef Simulation super;
    
    void calcGen();
};
