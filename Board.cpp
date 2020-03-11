#include "Board.h"

Board::Board(){}

Board::Board(int rows, int columns){
  m_rows = rows;
  m_columns = columns;
  m_arr = new Cell*[m_rows];
  // m_nextBoard = new Cell*[m_rows];

  for(int i = 0; i < m_rows; ++i){
    m_arr[i] = new Cell[m_columns];
    // m_nextBoard[i] = new Cell[m_columns];

    fill(m_arr[i], m_arr[i] + m_columns, Cell());
  }
}

Board::Board(int rows, int columns, float density){
  m_rows = rows;
  m_columns = columns;
  m_arr = new Cell*[m_rows];

  for(int i = 0; i < m_rows; ++i){
    m_arr[i] = new Cell[m_columns];
    fill(m_arr[i], m_arr[i] + m_columns, Cell());
  }

  int count = 0;
  int filled = (int) (m_rows * m_columns * density);

  while(count < filled){
    int x = (int)(rand() % m_rows);
    int y = (int)(rand() % m_columns);

    if(m_arr[x][y].getState() != 'X'){
      m_arr[x][y].setState('X');
      count += 1;
    }
  }
}

Board::Board(string fName){

}

Board::~Board(){
  delete m_arr;
}

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

Cell Board::getCell(int x, int y){
  return m_arr[x][y];
}

void Board::setCell(int x, int y, Cell c){
  m_arr[x][y] = c;
}

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

void Board::printBoard(int x, string fName){
  ofstream outFS;
  outFS.open(fName);

  outFS << "Generation " << x << ": " << endl;
  for(int r = 0; r < m_rows; ++r){
    for(int c = 0; c < m_columns; ++c){
      outFS << m_arr[r][c].getState();
    }
    outFS << endl;
  }

  outFS.close();
}
