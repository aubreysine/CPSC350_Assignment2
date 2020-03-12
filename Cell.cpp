#include "Cell.h"

Cell::Cell(){
  m_state = '-';
}

Cell::Cell(char state){
  m_state = state;
}

Cell::~Cell(){}

char Cell::getState(){
  return m_state;
}

void Cell::setState(char state){
  m_state = state;
}

//Returns state of cell for next generation based on count
char Cell::nextGen(int count){
  if(count == 2){
    return m_state; //State stays the same
  }else if(count == 3){
    return 'X';
  } else{
    return '-';
  }
}
