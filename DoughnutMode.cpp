#include "DoughnutMode.h"

DoughnutMode::DoughnutMode(){}

DoughnutMode::DoughnutMode(int rows, int columns, float density) : super(rows, columns, density){}

DoughnutMode::DoughnutMode(string fName) : super(fName){}

DoughnutMode::~DoughnutMode(){}

void DoughnutMode::calcGen(){
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
          int x = (i < 0 || i >= rows) ? (rows - abs(i)) : i;
          int y = (j < 0 || j >= columns) ? (columns - abs(j)) : j;

          if(m_gameBoard->getCell(x,y).getState() == 'X'){
            ++count;
          }
        }
      }
      m_nextBoard->setCell(r,c,Cell(m_gameBoard->getCell(r,c).nextGen(count)));
    }
  }
}
