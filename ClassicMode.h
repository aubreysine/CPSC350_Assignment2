#include "Simulation.h"

class ClassicMode : public Simulation{
  public:
    ClassicMode();
    ClassicMode(int rows, int columns, float density);
    ClassicMode(string fName);
    ~ClassicMode();

    typedef Simulation super;

    void calcGen();
};
