#include "DoughnutMode.h"

DoughnutMode::DoughnutMode(){}

//Overload constructor - calls constructor from simulation class
DoughnutMode::DoughnutMode(int rows, int columns, float density) : super(rows, columns, density){}

//Overload constructor - calls constructor from simulation class
DoughnutMode::DoughnutMode(ifstream &inFS) : super(inFS){}

DoughnutMode::~DoughnutMode(){}

//Calculates next generation and stores it in m_nextBoard
void DoughnutMode::calcGen(){
  int rows = m_gameBoard->getRows();
  int columns = m_gameBoard->getColumns();
  int count;

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

          //Set x and y to different values i or j are out of the array bounds
          int x = (i < 0 || i >= rows) ? (rows - abs(i)) : i;
          int y = (j < 0 || j >= columns) ? (columns - abs(j)) : j;

          //Adds to count if cell is alive
          if(m_gameBoard->getCell(x,y).getState() == 'X'){
            ++count;
          }
        }
      }
      //Calculates the cell's next generation and adds it to the next board
      m_nextBoard->setCell(r,c,Cell(m_gameBoard->getCell(r,c).nextGen(count)));
    }
  }
}
