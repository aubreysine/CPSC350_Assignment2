#include "Simulation.h"

class DoughnutMode : public Simulation{
  public:
    DoughnutMode();
    DoughnutMode(int rows, int columns, float density);
    DoughnutMode(ifstream &inFS);
    ~DoughnutMode();

    typedef Simulation super; //Initialized super to call from inherited class(Simulation)

    void calcGen();
};
