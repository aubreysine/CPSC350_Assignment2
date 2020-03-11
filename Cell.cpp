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

char Cell::nextGen(int count){
  if(count == 2){
    return m_state;
  }else if(count == 3){
    return 'X';
  } else{
    return '-';
  }
}
