#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;

class Cell{
  public:
    Cell();
    Cell(char state);
    ~Cell();


    char getState();
    void setState(char state);

    char nextGen(int count);
  private:
    char m_state;
};
#endif
