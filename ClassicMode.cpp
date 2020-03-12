#include "ClassicMode.h"

ClassicMode::ClassicMode(){}

//Overload constructor - calls constructor from simulation class
ClassicMode::ClassicMode(int rows, int columns, float density) : super(rows, columns, density){}

//Overload constructor - calls constructor from simulation class
ClassicMode::ClassicMode(ifstream &inFS) : super(inFS){}

ClassicMode::~ClassicMode(){}

//Calculates next generation and stores it in m_nextBoard
void ClassicMode::calcGen(){
  int rows = m_gameBoard->getRows();
  int columns = m_gameBoard->getColumns();
  int count; //neighbor count

  //Iterating through 2d array to find neighbor count
  for(int r = 0; r < rows; ++r){
    for(int c = 0; c < columns; ++c){
      count = 0;

      //Iterating through all cell neighbors
      for(int i = r-1; i <= r+1; ++i){
        for(int j = c-1; j <= c + 1; ++j){

          //Does not count the original cell
          if(i == r && j == c){
            continue;
          }

          //Checks to ensure index is in range and adds to count if its alive
          if(i >= 0 && i < rows && j >= 0 && j < columns){
            if(m_gameBoard->getCell(i,j).getState() == 'X'){
              ++count;
            }
          }
        }
      }
      //Calculates the cell's next generation and adds it to the next board
      m_nextBoard->setCell(r,c,Cell(m_gameBoard->getCell(r,c).nextGen(count)));
    }
  }
}
