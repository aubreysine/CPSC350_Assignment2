#include "MirrorMode.h"

MirrorMode::MirrorMode(){}

MirrorMode::MirrorMode(int rows, int columns, float density) : super(rows, columns, density){}

MirrorMode::MirrorMode(string fName) : super(fName){}

MirrorMode::~MirrorMode(){}

void MirrorMode::calcGen(){
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
          int x = (i < 0 || i >= rows) ? r : i;
          int y = (j < 0 || j >= columns) ? c : j;

          if(m_gameBoard->getCell(x,y).getState() == 'X'){
            ++count;
          }
        }
      }
      m_nextBoard->setCell(r,c,Cell(m_gameBoard->getCell(r,c).nextGen(count)));
    }
  }
}
