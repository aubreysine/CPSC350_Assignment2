#include "ClassicMode.h"

ClassicMode::ClassicMode(){}

ClassicMode::ClassicMode(int rows, int columns, float density) : super(rows, columns, density){}

ClassicMode::ClassicMode(string fName) : super(fName){}

ClassicMode::~ClassicMode(){}

void ClassicMode::calcGen(){
  int rows = m_gameBoard->getRows();
  int columns = m_gameBoard->getColumns();
  int count;

  for(int r = 0; r < rows; ++r){
    for(int c = 0; c < columns; ++c){
      count = 0;
      for(int i = r-1; i <= r+1; ++i){
        for(int j = c-1; j <= c + 1; ++j){

          if(i == r && j == c){
            continue;
          }

          if(i >= 0 && i < rows && j >= 0 && j < columns){
            if(m_gameBoard->getCell(i,j).getState() == 'X'){
              ++count;
            }
          }
        }
      }
      m_nextBoard->setCell(r,c,Cell(m_gameBoard->getCell(r,c).nextGen(count)));
    }
  }
}
