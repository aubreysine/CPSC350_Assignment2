#include "Simulation.h"

class ClassicMode : public Simulation{
  public:
    ClassicMode();
    ClassicMode(int rows, int columns, float density);
    ClassicMode(ifstream &inFS);
    ~ClassicMode();

    typedef Simulation super; //Initialized super to call from inherited class(Simulation)

    void calcGen();
};
