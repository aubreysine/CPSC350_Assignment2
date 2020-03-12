#include "Board.h"

Board::Board(){}

//Overload constructor - creates blank board from specified number of rows and columns
Board::Board(int rows, int columns){
  m_rows = rows;
  m_columns = columns;
  m_arr = new Cell*[m_rows];

  //2D array creation
  for(int i = 0; i < m_rows; ++i){
    m_arr[i] = new Cell[m_columns];
    fill(m_arr[i], m_arr[i] + m_columns, Cell()); //Filling array with default cells
  }
}

/**Overload constructor - creates board from specified number of rows and columns
and fills it randomly to a specified density of alive cells **/
Board::Board(int rows, int columns, float density){
  m_rows = rows;
  m_columns = columns;
  m_arr = new Cell*[m_rows];

  //2D Array creation
  for(int i = 0; i < m_rows; ++i){
    m_arr[i] = new Cell[m_columns];
    fill(m_arr[i], m_arr[i] + m_columns, Cell()); //Filling array with default cells
  }

  int count = 0;
  int filled = (int) (m_rows * m_columns * density); //total number of filled cells

  while(count < filled){
    //Randomized location in 2D array
    int x = (int)(rand() % m_rows);
    int y = (int)(rand() % m_columns);

    //Set index to alive if it's not already set to alive
    if(m_arr[x][y].getState() != 'X'){
      m_arr[x][y].setState('X');
      count += 1;
    }
  }
}

Board::Board(ifstream &inFS){
  string fCont,out;

  //Getting the rows and columns
  inFS >> m_rows >> m_columns;

  //Initializing the array
  m_arr = new Cell*[m_rows];
  for(int i = 0; i < m_rows; ++i){
    m_arr[i] = new Cell[m_columns];
    fill(m_arr[i], m_arr[i] + m_columns, Cell());
  }

  //Setting values for array
  for(int r = 0; r < m_rows; ++r){
    inFS >> fCont;
    for(int c = 0; c < m_columns; ++c){
      m_arr[r][c].setState(fCont[c]);
    }
  }
  inFS.close();
}

Board::~Board(){
  delete m_arr;
}

//Sets calling board equal to given board
void Board::setBoard(Board* arr){
  for(int r = 0; r < m_rows; ++r){
    for(int c = 0; c < m_columns; ++c){
      m_arr[r][c].setState(arr->getCell(r,c).getState());
    }
  }
}

int Board::getRows(){
  return m_rows;
}

int Board::getColumns(){
  return m_columns;
}

//Returns Cell of a given index
Cell Board::getCell(int x, int y){
  return m_arr[x][y];
}

//Sets Cell of a given index
void Board::setCell(int x, int y, Cell c){
  m_arr[x][y].setState(c.getState());
}

//Return boolean whether the calling board's values are equal to the given board
bool Board::isEqual(Board* arr){
  for(int r = 0; r < m_rows; ++r){
    for(int c = 0; c < m_columns; ++c){
      if(m_arr[r][c].getState() != arr->getCell(r,c).getState()){
        return false;
      }
    }
  }
  return true;
}

//Prints board to console with given generation number
void Board::printBoard(int x){
  cout << endl;
  cout << "Generation " << x << ": " << endl;
  for(int r = 0; r < m_rows; ++r){
    for(int c = 0; c < m_columns; ++c){
      cout << m_arr[r][c].getState();
    }
    cout << endl;
  }
}

//Prints board to given file with given generation number
void Board::printBoard(int x, ofstream& outFS){
  outFS << "Generation " << x << ": " << endl;
  for(int r = 0; r < m_rows; ++r){
    for(int c = 0; c < m_columns; ++c){
      outFS << m_arr[r][c].getState();
    }
    outFS << endl;
  }
}
