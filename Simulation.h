#ifndef SIMULATION_H
#define SIMULATION_H

#include "Board.h"
#include <cstdlib>
#include <unistd.h>

class Simulation{
  public:
    Simulation();
    Simulation(int rows, int columns, float density);
    Simulation(string fName);
    ~Simulation();

    void playGame(int output);
    void playGame(string fName, int cycles);
    virtual void calcGen();


  protected:
    Board *m_gameBoard;
    Board *m_nextBoard;
    Board *m_prevBoard;
};

#endif
