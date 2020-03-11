#include "Simulation.h"

class DoughnutMode : public Simulation{
  public:
    DoughnutMode();
    DoughnutMode(int rows, int columns, float density);
    DoughnutMode(string fName);
    ~DoughnutMode();

    typedef Simulation super;

    void calcGen();
};
